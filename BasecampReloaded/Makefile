prefix := ex

.PHONY: next
next:
    num=$$(ls $(parent) | grep -oP "(?<=^$(prefix))[0-9]{2}" | sort -n | tail -n 1); \
    if [ -z $$num ]; then \
        num=1; \
    else \
        num=$$((num+1)); \
    fi; \
    dirname="$(prefix)$$num"; \
    mkdir -p $(parent)/$$dirname && cd $(parent)/$$dirname
