# Requirements

There are package names for Arch Linux, but they should be similar for other
distributions.

## TeX Live Packages

* `texlive-core`
* `texlive-langcyrillic`
* `texlive-latexextra`
* `texlive-bibtexextra`

Package `texlive-bibtexextra` used only for `common` preamble for BibLaTeX and
Biber support. `gost` preamble uses BibTeX.

## Fonts

* `ttf-linux-libertine`
* `ttf-droid`
* `ttf-asana-math` (AUR)

Asana Math also included in a `texlive-fontsextra` package, but it is very huge.
If you have it installed, simply just don’t install `ttf-asana-math`.

## Other tools

* `python2-pygments`

Pygments is a dependency for a `minted` TeX package. It prints listings without
all headache of `listings` package (and with more lexers and colors, yarrr).
