NAME			=		bank

#############################################################################
#																			#
#								COMPILER									#
#																			#
#############################################################################

CXX				=	g++

CXXFLAGS		=	-MMD -Wall -Wextra -Werror -std=c++98

INC				=	-I includes/

SILENT			=	--no-print-directory

#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH		=	srcs/
OBJS_PATH		=	objs/

#############################################################################
#																			#
#									FILES									#
#																			#
#############################################################################

SRCS				=	main.cpp 		\
						Bank.cpp 		\
						Account.cpp
					

OBJS			=	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))

DEPS			=	$(OBJS:.o=.d)

#############################################################################
#																			#
#									RULES									#
#																			#
#############################################################################

all:				$(NAME)

${NAME}:			${OBJS}
					$(CXX) $(OBJS) -o $@

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.cpp
					@mkdir -p $(dir $@)
					$(CXX) -MMD $(CXXFLAGS) -c $< -o $@ $(INC)

clean:
					@rm -rf $(OBJS_PATH)
					@echo "Objects cleaned!"
					
fclean:				clean
					@rm -f $(NAME)

re:					fclean
					@make all $(SILENT)

-include $(DEPS)
.PHONY:				all clean fclean re
