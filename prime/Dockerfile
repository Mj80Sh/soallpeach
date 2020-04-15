FROM gcc
WORKDIR /app

COPY main.c main.c

RUN gcc main.c  -Wall -o main

ENTRYPOINT ["./main"]

