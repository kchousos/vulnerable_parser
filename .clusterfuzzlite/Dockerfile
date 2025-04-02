FROM gcr.io/oss-fuzz-base/base-builder:v1
RUN apt-get update && apt-get install -y clang
COPY . $SRC/vulnerable_parser
WORKDIR vulnerable_parser
COPY .clusterfuzzlite/build.sh $SRC/
