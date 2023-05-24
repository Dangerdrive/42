UNITY_DIR = ./Unity
CC = gcc
CFLAG = -Wall -Wextra -Werror -std=c99
RM = rm -f
COLOR_TESTS =-D UNITY_OUTPUT_COLOR

NAME_TESTE = gnl_test

SRC_FILES =\
	$(UNITY_DIR)/src/unity.c \
	$(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
	~/Documents/42/Fase1/2.Get_next_line/*.c \
	~/Documents/42/Fase1/2.Get_next_line/test/*.c \
	~/Documents/42/Fase1/2.Get_next_line/test/test_group/*.c

INCLUDE_DIR =-Isrc -I$(UNITY_DIR)/src -I$(UNITY_DIR)/extras/fixture/src -I ~/Documents/42/Fase1/2.Get_next_line
SYMBOLS =-DUNITY_FIXTURE_NO_EXTRAS

all: clean default

default:
	$(CC)$(CFlAGS)  $(INCLUDE_DIR) $(SYMBOLS) $(SRC_FILES) -o $(NAME_TESTE) $(COLOR_TESTS)
	- ./$(NAME_TESTE) -v

clean:
	$(RM) $(NAME_TESTE)
