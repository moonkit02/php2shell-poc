# Web server only, no PHP runtime installed here.
FROM debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends nginx && rm -rf /var/lib/apt/lists/*
