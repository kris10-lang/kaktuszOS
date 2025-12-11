compile:
	sh/compile.sh

install:
	sh/install.sh

test:
	sh/test.sh

all:
	sh/compile.sh
	sh/install.sh
	sh/test.sh
git:
	git add .
	git commit -m "Update kaktuszOS code"
	git push
