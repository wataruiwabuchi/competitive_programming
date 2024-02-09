# go の競技プログラミング用環境を作成するための Dockerfile
# 以下のコマンドでビルドする
FROM golang:latest

# 以下のコマンドでビルドする
# docker build -t go-competitive-programming .
# 以下のコマンドでコンテナを起動する
# docker run -it --rm --name go-competitive-programming go-competitive-programming
# 以下のコマンドでコンテナに入る
# docker exec -it go-competitive-programming /bin/bash
# RUN go install gopls@latest

RUN apt-get update && \
    apt-get install -y python3 python3-pip && \
    rm -rf /var/lib/apt/lists/*
RUN pip3 install online-judge-tools