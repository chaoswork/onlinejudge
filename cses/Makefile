# 获取当前目录下最新的 .cpp 文件
NEWEST_CPP := $(shell ls -t *.cpp 2>/dev/null | head -n1)
NEWEST_PY := $(shell ls -t *.py 2>/dev/null | head -n1)
# 编译最新的 .cpp 文件
.PHONY: all
all:
ifeq ($(NEWEST_CPP),)
	@echo "No .cpp files found in the current directory."
else
	g++ $(NEWEST_CPP) --std=c++11 && cat test.in | ./a.out
endif

# 清理生成的可执行文件
.PHONY: clean
clean:
	rm -f *.out

build:
	g++ $(NEWEST_CPP)

test:
	cat test.in | ./a.out

pytest:
	cat test.in | python $(NEWEST_PY)
