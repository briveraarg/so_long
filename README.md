# 🎮 so_long

**so_long** es un pequeño juego en 2D hecho en C usando la librería gráfica [MLX42](https://github.com/codam-coding-college/MLX42), como parte del programa 42. El objetivo del juego es recorrer un mapa recolectando todos los ítems (`C`) y llegar a la salida (`E`), todo en un entorno visual simpático con referencias al fútbol argentino 😄⚽

---

## 🧠 Requisitos

- Linux o macOS
- [`cmake`](https://cmake.org/) instalado (requerido por MLX42)
- Las siguientes librerías incluidas:
  - [libft](https://github.com/42Paris/42libft)
  - [ft_printf](https://github.com/42Paris/printf)
  - [MLX42](https://github.com/codam-coding-college/MLX42)

---

## ⚙️ Compilación

Antes de compilar, asegurate de tener `cmake` instalado para poder construir la MLX42.

### 1. Compilar el proyecto

```bash
make
```

Este comando:

- Compila automáticamente las librerías externas:
  - [`libft`](libs/libft)
  - [`ft_printf`](libs/ft_printf)
  - [`MLX42`](libs/MLX42)
- Genera el ejecutable `so_long` en el directorio raíz.

### 2. Limpiar archivos intermedios

- Para eliminar los archivos objeto (`.o`):

```bash
make clean
```

- Para limpiar completamente (incluye binarios y carpeta de build de MLX42):

```bash
make fclean
```

- Para recompilar desde cero:

```bash
make re
```

### 3. Verificación de Norminette

```bash
make norminette
```

💡 **Nota**: Si estás en Linux, tu `Makefile` enlaza automáticamente las dependencias necesarias (`-lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXi`). En macOS, se usan los frameworks nativos de Cocoa, OpenGL e IOKit.

---

## 🕹️ Cómo jugar

```bash
./so_long maps/mapa.ber
```

### Controles

| Tecla       | Acción             |
|-------------|--------------------|
| ⬆️ / ⬇️ / ⬅️ / ➡️ | Mover al jugador   |
| ESC         | Salir del juego    |

Tu misión es recolectar todos los ítems (`C`) y llegar a la salida (`E`). Cuando juntás todo, la salida se abre mágicamente y podés escapar para ganar.

---

## 🗺️ Formato del mapa `.ber`

El mapa debe estar formado por los siguientes caracteres:

- `1` → Pared
- `0` → Espacio vacío
- `P` → Posición inicial del jugador
- `C` → Ítem recolectable
- `E` → Salida

- 1111111111111111
- 10010000000000C1
- 1000011111000001
- 1P0000CE00000001
- 1111111111111111

Reglas básicas del mapa:

- Rectangular
- Rodeado de paredes
- Debe haber **exactamente un** `P` y `E`, y al menos un `C`

---

## 📁 Estructura del proyecto

```
so_long/
├── src/
│   ├── check_map_*.c       # Validación de mapa
│   ├── initialize_game_*.c # Inicialización de estructuras y gráficos
│   ├── move_player_*.c     # Movimiento y lógica del jugador
│   ├── error_exit.c        # Manejo de errores
│   ├── utils.c             # Utilidades (memoria, validaciones)
│   └── main.c              # Función principal
├── libs/                   # Librerías externas: MLX42, libft, ft_printf
├── textures/               # Imágenes PNG usadas en el juego
├── so_long.h               # Header principal
├── Makefile                # Compilador automático
└── maps/                   # Mapas de ejemplo
```

---

## 🌈 Créditos y detalles divertidos

- El juego incluye texturas personalizadas.
- Los mensajes en terminal son en tono humorísticos 😉

---

## 🧪 Testing y normas

- Cumple con la Norminette.
- Maneja errores de archivos, mapas y memoria (valgrind OK).
- Texturas cargadas desde `./textures/*.png` (validadas antes de iniciar)

---

## 💬 Contacto

Creado por **Brenda Rivera**  
📧 brivera@student.42madrid.com  
🇦🇷 Desde Argentina, estudiando en 42 Madrid  

