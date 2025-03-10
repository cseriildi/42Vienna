DOCKER_IMG = ubuntu-img

DOCKERFILE_PATH = .

build-image:
	docker build -t $(DOCKER_IMG) $(DOCKERFILE_PATH)
	@echo "Docker image $(DOCKER_IMG) built successfully."

run-container:
	docker run --rm -it \
		-v $(PWD)/..:/work \
		-w /work \
		$(DOCKER_IMG) \
		zsh

clean-image:
	docker rmi $(DOCKER_IMG)
	@echo "Docker image $(DOCKER_IMG) removed."

.PHONY: build-image run-container clean-image
