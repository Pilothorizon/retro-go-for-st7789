FROM espressif/idf:release-v5.1
WORKDIR /app
ADD . /app
SHELL ["/bin/bash", "-c"]
RUN . /opt/esp/idf/export.sh && \
	rm -rf /app/gwenesis /app/fmsx && \
	python rg_tool.py --target=retro-esp32 --no-networking release
