FROM ubuntu:latest

RUN  apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
	bear \
	clang \
	clangd \
	cmake \
	cppcheck \
	valgrind \
	git \
	zsh \
	curl \
	build-essential \
	&& apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

RUN ln -sf /usr/bin/clang++ /usr/bin/c++

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" || true

RUN cd $HOME \
	&& git clone https://github.com/cseriildi/dotfiles \
	&& chmod +x dotfiles/setup.sh \
	&& dotfiles/setup.sh

WORKDIR /work