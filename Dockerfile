FROM gcc
COPY app /app/app
WORKDIR /app
ENTRYPOINT ["/app/app"]
