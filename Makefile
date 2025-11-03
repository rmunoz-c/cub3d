NAME        := cub3D
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -Iincludes -Ilibft -Iminilibx-linux

# MiniLibX
MLX_DIR     := minilibx-linux
MLX_LIB_A   := $(MLX_DIR)/libmlx.a
X11_LIBS    := -lXext -lX11 -lm -lz

# libft
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

BUILD       := build

# ----------------- DEBUG -----------------
DEBUG ?= 0
ifeq ($(DEBUG),1)
CFLAGS += -g -DDEBUG
SRC_DEBUG := src/debug/debug_player.c
endif
# ----------------------------------------

SRC := \
  src/main.c \
  src/loop.c \
  src/events/events.c \
  src/utils/mlx_utils.c \
  src/init/init_mlx.c \
  src/init/init_player.c \
  src/parser/parser.c \
  src/parser/header_scan.c \
  src/parser/map_reader.c \
  src/parser/map_rect.c \
  src/parser/map_checker.c \
  src/parser/map_checker_utils.c \
  src/parser/color_parser.c \
  src/parser/player_spawn.c \
  src/parser/texture_checker.c \
  $(SRC_DEBUG)

OBJ := $(SRC:%.c=$(BUILD)/%.o)

all: $(MLX_LIB_A) $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB_A) $(LIBFT_A) $(X11_LIBS) -o $(NAME)

$(BUILD)/%.o: %.c | $(BUILD)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

$(MLX_LIB_A):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD)
	$(MAKE) -C $(MLX_DIR) clean || true
	$(MAKE) -C $(LIBFT_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

# Compilación en modo debug (activa -g y -DDEBUG)
debug:
	$(MAKE) DEBUG=1

# Ejecutar con un mapa: make run MAP=maps/ok_player_N.cub
run: all
	@if [ -z "$(MAP)" ]; then \
		echo "Uso: make run MAP=path/al/archivo.cub"; \
	else \
		./$(NAME) $(MAP); \
	fi

.PHONY: all clean fclean re debug run
