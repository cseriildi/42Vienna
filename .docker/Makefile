DOCKER_IMG = ubuntu-img

DOCKERFILE_PATH = .

.PHONY: build-image
build-image:
	@docker build -t $(DOCKER_IMG) $(DOCKERFILE_PATH)
	@echo "$(GREEN)Docker image $(DOCKER_IMG) built successfully.$(RESET)"

.PHONY: run-container
run-container: build-image
	@docker run --rm -it \
		-v $(PWD)/..:$(PWD)/.. \
		-w $(PWD)/.. \
		$(DOCKER_IMG) \
		zsh

.PHONY: clean-image
clean-image:
	@if [ -n "$(shell docker images -q $(DOCKER_IMG))" ]; then \
		docker rmi $(DOCKER_IMG) > /dev/null 2>&1; \
		echo "$(GREEN)Docker image $(DOCKER_IMG) removed.$(RESET)"; \
	else \
		echo "$(RED)Docker image $(DOCKER_IMG) does not exist.$(RESET)"; \
	fi

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m
