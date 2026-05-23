FROM espressif/idf:release-v5.1
WORKDIR /app
ADD . /app
SHELL ["/bin/bash", "-c"]
RUN . /opt/esp/idf/export.sh && \
    python rg_tool.py --target=esp32-s3-devkit --no-networking clean && \
    python rg_tool.py --target=esp32-s3-devkit --no-networking build-img launcher retro-core prboom-go gwenesis snes9x-go fmsx-go
