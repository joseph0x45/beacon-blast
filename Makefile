PORT ?= /dev/ttyACM0
BAUD ?= 11500

flash:
	idf.py --port $(PORT) flash monitor

erase:
	esptool.py --chip esp32c3 --port $(PORT) --baud $(BAUD) erase_flash

erase_flash_then_flash: erase
	idf.py --port $(PORT) flash monitor

update-compile-commands:
	cp ./build/compile_commands.json .
