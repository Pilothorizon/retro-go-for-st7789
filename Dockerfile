FROM espressif/idf:release-v5.1
WORKDIR /app
ADD . /app
SHELL ["/bin/bash", "-c"]
RUN . /opt/esp/idf/export.sh && \
	python rg_tool.py --target=retro-esp32 --no-networking clean && \
	python rg_tool.py --target=retro-esp32 --no-networking release launcher retro-core prboom-go
