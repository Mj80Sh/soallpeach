FROM gcc
WORKDIR /app

COPY main.c main.c

RUN gcc main.c -O3 -ffast-math -o main

ENTRYPOINT ["./main"]

