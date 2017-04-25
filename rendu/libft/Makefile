# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 02:24:02 by schiad            #+#    #+#              #
#    Updated: 2017/04/25 20:25:18 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re bart

NAME = libft.a
all: $(NAME)

CC = gcc

FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude
SRC_PATH = src
OBJ_PATH = obj
SRC_NAME =	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_itoa.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_putdigit_fd.c\
			ft_putllong.c\
			ft_putllong_fd.c\
			ft_putnbr_fd.c\
			ft_putnbr.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

$(OBJ_PATH)/%.o :$(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

$(NAME): $(OBJ)
	$(RED_COLOR)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[34mlibft.a created.\033[0m"
	@ranlib $(NAME)
	@echo "\033[92mlibft.a indexed. ENJOY\033[0m"

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mObjects files deleted.\033[0m"

fclean: clean bart
	rm -fv $(NAME)
	@echo "\033[31mlibft.a deleted :-(.\033[0m"

re: fclean all

bart: 
	@echo "\033[2J"
	@echo "\033[0;0H"
	@echo "\033[30;107m"
	@echo "                                            \033[103mJZ.Z}Y\033[107m  \033[103mZ0!\033[107m  \033[103mUC\033[107m                      "
	@echo "                                            \033[103mzuLzxvia[r0\033[107m \033[103mLuc?;\033[107m \033[103mojv,\033[107m               "
	@echo "                                            \033[103mu nn  xu  xCx  XIhxuY /Z1.\033[107m  \033[103m+\033[107m        "
	@echo "                                           \033[103mlv          n   ncn  U0cvu. Cx\033[107m        "
	@echo "                                           \033[103mrv                   ux  0UjnJ nOf.\033[107m   "
	@echo "                                          \033[103m Lu                       rnn OOrnC.\033[107m   "
	@echo "                                          \033[103m+0x                           nn  L0tj.\033[107m"
	@echo "                                          \033[103m}Ux                               uxnY,\033[107m"
	@echo "                                          \033[103mYn                                  0\033[107m  "
	@echo "                                         \033[103m<Q[                                 a.\033[107m  "
	@echo "                                         \033[103mtxu                                r_.\033[107m  "
	@echo "                                         \033[103mO[x                                Y\033[107m    "
	@echo "                                         \033[103mfx                                 C.\033[107m   "
	@echo "                                         \033[103mn                                 C?.\033[107m   "
	@echo "                                        \033[103m?v                                 U\033[107m     "
	@echo "                                        \033[103mjv                                a;\033[107m     "
	@echo "                                       \033[103m+Ox            JhZOkfr            r1\033[107m      "
	@echo "                                       \033[103mrLx         za\033[107m  . .. ,\033[103mnc           ,\033[107m      "
	@echo "                                      \033[103m_o[         Y,\033[107m         \033[103m;ikr         ,\033[107m      "
	@echo "                                      \033[103mUv         J\033[107m              \033[103mXUz}zC0]zr).\033[107m     "
	@echo "                                      \033[103mJu         \033[107mU.   jq\033[107m        > \033[103m,,,. )b}(.\033[107m     "
	@echo "                                      \033[103mn         \033[107mfv    #@\033[107m        .      . \033[103mJ\033[107m       "
	@echo "                                     \033[103m{v          \033[107mC              ~        -\033[107m       "
	@echo "                                     \033[103mZn          O\033[107m              x    p@.  .      "
	@echo "                                    \033[103mvCx          [1\033[107m            /.    ;1   .      "
	@echo "                                 \033[103mYZJXou          nca[\033[107m         . |        c       "
	@echo "                                \033[103mYczwXc             xcXoC}}uQJufUQ\033[107m       /        "
	@echo "                                \033[103mfutruJn              nnurrcxn nxx[rLO{I|\033[107m \033[103m.\033[107m       "
	@echo "                                \033[103m0rx  x  Lu                         xu]Y.\033[107m         "
	@echo "                                 \033[103m1qJcoc[}z                            f\033[107m          "
	@echo "                                \033[103m{YrcaxYO[Oc                     Xv    O\033[107m          "
	@echo "                                \033[103mjn zz\033[107mr. v ;\033[103mZ]x                  cLO0Z|\033[107m           "
	@echo "                              \033[103m1Qx    r>O\033[107m-  /\033[103m/av                  xzv~.\033[107m           "
	@echo "                          \033[103m?QapO nr   zai.\033[107m U(,  \033[103moj]z                L\033[107m             "
	@echo "                         \033[48;5;202mczLCCLttC\033[103mhc  nnZn\033[107m , _Z  IZv\033[103m\033[103m               Y\033[107m             "
	@echo "                    \033[48;5;202miaQtqoz        Jtooc\033[103m noC!U<\033[107m   C  \033[103m)XCu           Y\033[107m            "
	@echo "                  \033[48;5;202mvOfoojt           CtOac\033[103mxuvtX00i\033[107m    ,. \033[103m,n00c       Y.\033[107m           "
	@echo "             \033[48;5;202m+tXo0LC zf  J            tLjL\033[103mczczjZ\033[107m          .. \033[103m+{LUYf?\033[107m             "
	@echo "          \033[48;5;202mnXJffLCL                       j\033[103mottQJ<\033[107m             .,.  ..\033[107m             "
	@echo "        \033[48;5;202maLft                      UahoZ0QaUU\033[107m                                     "
	@echo "     \033[48;5;202m<oCC                       aJjttCLLLtzo\033[107m                                     "
	@echo "     \033[48;5;202mYL                       OQC          j(.\033[107m                                   "
	@echo "    \033[48;5;202mjjJhuuxfLYdhYf           dzf            o.\033[107m                                   "
	@echo "    \033[48;5;202mZhrnnnnnnnnv[nCQOC       0j ba0j        a!\033[107m                                   "
	@echo "    \033[103mvc            xzv\033[48;5;202mujQj    QYQnnujaOL     h!\033[107m                                   "
	@echo "   \033[103m>0n      kXu       ucc\033[48;5;202m0j  jk\033[103mc   nx[\033[48;5;202mkL    o.\033[107m                                   "
	@echo "   \033[103mLz      xh]u          xn\033[48;5;202maUbr\033[103m       u\033[48;5;202muhL  {.\033[107m                                   "
	@echo "   \033[103mo[      a[x             n\033[48;5;202mr\033[103mn          \033[48;5;202m0XtU\033[107m                                     "
	@echo "  \033[103m(Yr      Uv               tv         d\033[48;5;202mjjW1,\033[107m                                    "
	@echo "  \033[103m(Yr      Ju               Zv        q\033[48;5;202maoI\033[107m                                       "
	@echo "  \033[103m.a[      Xv               0n        Y\033[48;5;202mCY,\033[107m                                       "
	@echo "   \033[103mut      bv               Qx        C \033[48;5;202mu,\033[107m                                       "
	@echo "   \033[103m;Yn     chn              0n        0\033[48;5;202m}\033[107m                                         "
	@echo "     \033[103mzu     c0v             Zu        ..\033[107m                                         "
	@echo "     \033[103m~YLx    nbxu           tc       [).\033[107m                                         "
	@echo "      \033[103m. doXj  nrQu          rn       z0?\033[107m                                         "
	@echo "        \033[103m.|Zn    n QbJfLQou   ac       xjt.\033[107m                                       "
	@echo "          \033[103m>v      cO\033[107m    \033[103m?ox  uk]       x[x\033[107m                                       "
	@echo "          \033[103m.Yv      r|\033[107m   , \033[103mXc  xon        vfL.\033[107m                                    "
	@echo "           \033[103m/Zr     zh~\033[107m     \033[103mJx nn          xu,\033[107m                                    "
	@echo "            \033[103mxj      rX\033[107m      \033[103mfu rUu          I.\033[107m                                   "
	@echo "        \033[44mIXMMtzn\033[103m      \033[44maMW**WW+v\033[103m  U\033[44mUY\033[103mx     Cu -\033[107m                                    "
	@echo "        \033[44mWp .?ux\033[103m      p*     \033[44m<MMmpqWc\033[103m  \033[44mz\033[103m  \033[44mn\033[103m \033[44mO\033[107m                                     "
	@echo "        \033[44m~w wqm\033[103m.<Wpbbw\033[44m!      w\033[103mw    \033[44mqx kJqlt/\033[107m                                      "
	@echo "        \033[44m{{*    wwqwwww            wqwqqwW ,\033[107m                                      "
	@echo "        \033[44mWw ,              .           M?X.\033[107m                                       "
	@echo "        \033[44m0* q                           .J,\033[107m                                       "
	@echo "        \033[44mW                               dh-\033[107m                                      "
	@echo "        \033[44m*                                w,).\033[107m                                    "
	@echo "       \033[44m!M                .               /fi\033[107m                                     "
	@echo "       \033[44m_m               .I               wqpMh<.\033[107m                                 "
	@echo "        \033[44mW          pf(!w   qq                wmI\033[107m                                 "
	@echo "       \033[44m+w         Q., [q                       mh\033[107m                                "
	@echo "       \033[44mzd         m+|;p                        d_t.\033[107m                              "
	@echo "       \033[44mtdi           ?oi, *                 <a|.<Y.\033[107m                              "
	@echo "      \033[44m_X    \033[107m-!|/?-\033[44m     }xjLZbM_;       + Zc+  ~j.\033[107m                                "
	@echo "      \033[44m. +?{tJLtttLJx(!-   +..    ..      ,,}v? ,\033[107m                                 "
	@echo "                           \033[44mi{zzfzunxfjzn[~\033[107m                                       "
	@echo "                            \033[44m...\033[107m       \033[44m,,,\033[107m                                        "

