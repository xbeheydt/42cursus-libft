<!--

	README.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/21

-->
# 42 Cursus - Libft

It's first bigger 42 project. Make your own lib named **libft**.

My libft includes `ft_printft` and `get_next_line` too.

## How to build

**cmake**

_In my case, I'm using cmake to configure my IDE for dev in cross-platform._

```bash
# inside repo
mkdir build
cd build
cmake ..
make ft
```

> Now in build folder you can found `libft.a`.

**make**

_In case of normal dev at 42SChool._

```bash
make
```

> Static library can be found in `<repo>/build/lib/libft.a`
> and headers in `<repo>/build/include`.

## API Documentation

For more informations go to [summary](./docs/README.md).
