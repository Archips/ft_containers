FT_NAME				:=	ft_containers
STD_NAME			:=  std_containers

FT_NAME_BONUS		:=	ft_containers_bonus
STD_NAME_BONUS		:=  std_containers_bonus

DEFINE_FT			= -D NAMESPACE="ft"
DEFINE_STD			= -D NAMESPACE="std"

CXX					:=	c++
CXXFLAGS			:=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -fsanitize=address -g3
$(FT_NAME): 		CXXFLAGS += $(DEFINE_FT)
$(FT_NAME_BONUS): 	CXXFLAGS += $(DEFINE_FT)
$(STD_NAME): 		CXXFLAGS += $(DEFINE_STD)
$(STD_NAME_BONUS): 	CXXFLAGS += $(DEFINE_STD)

CPPFLAGS			:=  -I ./includes
RM					:= 	rm -rf
DIR_DUP				= mkdir -p $(@D)

SRCS				:= \
			   		main_mandatory.cpp \

SRCS_BONUS 			:= \
			 	 	main_bonus.cpp

FT_OBJ_DIR			:= ft_objs
STD_OBJ_DIR			:= std_objs

FT_OBJ_DIR_BONUS	:= ft_objs
STD_OBJ_DIR_BONUS	:= std_objs

FT_OBJS				:= $(SRCS:%.cpp=$(FT_OBJ_DIR)/%.o)
STD_OBJS			:= $(SRCS:%.cpp=$(STD_OBJ_DIR)/%.o)

FT_OBJS_BONUS		:= $(SRCS_BONUS:%.cpp=$(FT_OBJ_DIR_BONUS)/%.o)
STD_OBJS_BONUS		:= $(SRCS_BONUS:%.cpp=$(STD_OBJ_DIR_BONUS)/%.o)

FT_DEPS				:= $(FT_OBJS:.o=.d)
STD_DEPS			:= $(STD_OBJS:.o=.d)

FT_DEPS_BONUS		:= $(FT_OBJS_BONUS:.o=.d)
STD_DEPS_BONUS		:= $(STD_OBJS_BONUS:.o=.d)

all:				$(FT_NAME) $(STD_NAME)


$(FT_NAME):			$(FT_OBJS)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(FT_OBJS) -o $(FT_NAME)
					$(info CREATE: $(FT_NAME))

$(STD_NAME):		$(STD_OBJS)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(STD_OBJS) -o $(STD_NAME)
					$(info CREATE: $(STD_NAME))
	
$(FT_OBJ_DIR)/%.o: %.cpp
					$(DIR_DUP)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
					$(info CREATE : $@)

$(STD_OBJ_DIR)/%.o: %.cpp
					$(DIR_DUP)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
	
bonus:				$(FT_NAME_BONUS) $(STD_NAME_BONUS)

$(FT_NAME_BONUS):	$(FT_OBJS_BONUS)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(FT_OBJS_BONUS) -o $(FT_NAME_BONUS)
					$(info CREATE: $(FT_NAME_BONUS))

$(STD_NAME_BONUS):	$(STD_OBJS_BONUS)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(STD_OBJS_BONUS) -o $(STD_NAME_BONUS)
					$(info CREATE: $(STD_NAME_BONUS))
	
$(FT_OBJ_DIR_BONUS)/%.o: %.cpp
					$(DIR_DUP)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
					$(info CREATE : $@)

$(STD_OBJ_DIR_BONUS)/%.o: %.cpp
					$(DIR_DUP)
					$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@


-include $(FT_DEPS) $(STD_DEPS) $(FT_DEPS_BONUS) $(STD_DEPS_BONUS)

clean:
					$(RM) $(FT_OBJ_DIR) $(STD_OBJ_DIR) $(FT_OBJS_DIR_BONUS) $(STD_OBJS_DIR_BONUS)
					$(info REMOVED : object files)

fclean:				clean
					$(RM) $(FT_NAME) $(STD_NAME) $(FT_NAME_BONUS) $(STD_NAME_BONUS)
					$(info REMOVED : binary file)

re:					fclean all

.PHONY:				all clean fclean re bonus
