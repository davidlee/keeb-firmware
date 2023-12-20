USER = davidlee
KEYBOARDS = lulu planck preonic

# keyboard name
NAME_lulu = lulu
NAME_planck = planck/rev6_drop
NAME_preonic = preonic/rev3_drop

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	# this pulls newer upstream changes:
	# git submodule update --remote

	# cleanup old symlinks
	# -f so non-existence is not an error
	rm -f qmk_firmware/keyboards/boardsource/lulu/keymaps/$(USER)
	rm -f qmk_firmware/keyboards/planck/keymaps/$(USER)
	rm -f qmk_firmware/keyboards/preonic/keymaps/$(USER)
	rm -f qmk_firmware/users/$(USER)
	echo "done cleanup ..."

	# add new symlinks
	ln -s $(shell pwd)/lulu qmk_firmware/keyboards/boardsource/lulu/keymaps/$(USER)
	ln -s $(shell pwd)/planck qmk_firmware/keyboards/planck/keymaps/$(USER)
	ln -s $(shell pwd)/preonic qmk_firmware/keyboards/preonic/keymaps/$(USER)
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	echo "done symlinking ..."

	# run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(NAME_$@) || echo "compaints!"
	echo "done linting ..."

	# run build
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(NAME_$@):$(USER)

	# cleanup symlinks
	rm -f qmk_firmware/keyboards/boardsource/lulu/keymaps/$(USER)
	rm -f qmk_firmware/keyboards/planck/keymaps/$(USER)
	rm -f qmk_firmware/keyboards/preonic/keymaps/$(USER)
	rm -f qmk_firmware/users/$(USER)

clean:
	rm qmk_firmware/keyboards/boardsource/lulu/keymaps/$(USER)
	rm qmk_firmware/keyboards/planck/keymaps/$(USER)
	rm qmk_firmware/keyboards/preonic/keymaps/$(USER)
	rm qmk_firmware/users/$(USER)
	rm -rf ./build
	# rm ./qmk_firmware

