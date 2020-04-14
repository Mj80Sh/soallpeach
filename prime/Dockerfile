FROM gcc:4.9
WORKDIR /app

COPY main.c main.c

RUN gcc main.c -O3 -Wall -ffast-math -o main

ENTRYPOINT ["./main"]

