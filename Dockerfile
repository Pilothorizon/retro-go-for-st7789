FROM espressif/idf:release-v5.1
WORKDIR /app
ADD . /app
SHELL ["/bin/bash", "-c"]
RUN . /opt/esp/idf/export.sh && \
	python rg_tool.py --target=retro-esp32 --no-networking release && \
	echo "=== ALL BIN FILES ===" && \
	find /app -name "*.bin" | sort && \
	echo "=== COPYING FILES ===" && \
	cp $(find /app/launcher/build -name "partition-table.bin" | head -1) /app/partition-table.bin && \
	cp $(find /app/launcher/build -name "bootloader.bin" | head -1) /app/bootloader.bin && \
	echo "=== DONE ==="
