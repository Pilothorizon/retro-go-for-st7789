FROM espressif/idf:release-v5.1
WORKDIR /app
ADD . /app
# Build
SHELL ["/bin/bash", "-c"]
RUN . /opt/esp/idf/export.sh && \
	python rg_tool.py --target=retro-esp32 release
 
