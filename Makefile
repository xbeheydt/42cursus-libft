# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2022/03/09 11:25:24 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re tests

BUILD_DIR		?= $(PWD)/build
OBJ_DIR			?= ${BUILD_DIR}/obj
INCLUDE_DIR		?= ${BUILD_DIR}/include
LIB_DIR			?= ${BUILD_DIR}/lib
EXE_DIR			?= ${BUILD_DIR}/bin
SRC_DIR			= $(CURDIR)/src
HEADER_DIR		= $(CURDIR)/include

NAME			= ${LIB_DIR}/libft.a

HEADERS			= libft/include/libft.h
INCLUDES		= $(addprefix ${INCLUDE_DIR}/, $(addsuffix .h, $(notdir $(basename ${HEADERS}))))
SRCS			= $(wildcard ${SRC_DIR}/ft_*.c ${SRC_DIR}/*/ft_*.c)
OBJS 			= $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

SRCS_TEST		= $(wildcard ${SRC_DIR}/.test_*.c ${SRC_DIR}/*/.test_*.c)

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS			+= -g3
endif
IFLAGS			= -I${HEADER_DIR}

VPATH			= $(sort $(dir $(SRCS)))

NORM			= norminette
RM				= rm -rf
MKDIR			= mkdir -p
CP				= cp

all: $(NAME) $(INCLUDES)

$(NAME): ${INCLUDES} ${OBJS}
	$(MKDIR) ${LIB_DIR}
	ar rcs $@ ${OBJS}
	ranlib $@

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

$(INCLUDE_DIR)/%: ${HEADER_DIR}/%
	$(MKDIR) ${INCLUDE_DIR}
	$(CP) $< $@

norm:
	@$(NORM) ${HEADER_DIR} ${SRC_DIR}

clean:
	${RM} ${OBJS}

fclean: clean
	$(RM) $(LIB_DIR)/${NAME}
	$(RM) $(INCLUDES)
	$(RM) ${EXE_DIR}/a.out

del-build:
	$(RM) ${BUILD_DIR}

re: fclean all

tests: $(EXE_DIR)/a.out

$(EXE_DIR)/a.out: re
	$(MKDIR) ${EXE_DIR}
	$(CC) ${CFLAGS} ${IFLAGS} -I. -L${LIB_DIR} ${SRCS_TEST} .test_main.c -lft
	./${EXE_DIR}/a.out