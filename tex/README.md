# Requirements

There are package names for Arch Linux, but they should be similar for other
distributions.

## TeX Live Packages

* `texlive-core`
* `texlive-latexextra`
* `texlive-langcyrillic`

## Fonts

### `common`

* `ttf-linux-libertine`
* `ttf-droid`
* `ttf-paratype` (AUR)
* `ttf-asana-math` (AUR)

Asana Math is also included in the `texlive-fontsextra` package, but it is very huge.
If you have it installed, simply don’t install the `ttf-asana-math` package.

### `gost`

* `otf-cm-unicode` (AUR)

## Tools

* `python2-pygments`

Pygments is a dependency for a `minted` TeX package. It prints listings without
all headache of `listings` package (and with more lexers and colors, yarrr).
