TEX_FILES = $(wildcard *.tex)
BIB_FILES = $(wildcard *.bib)
IMG_SRCS = $(wildcard Figures/*.pdf)

all: seminarpaper.pdf

seminarpaper.pdf: $(TEX_FILES) $(BIB_FILES) $(IMG_SRCS) Makefile
	pdflatex seminarpaper.tex
	bibtex seminarpaper
	pdflatex seminarpaper.tex
	pdflatex seminarpaper.tex
clean:
	rm -f *.aux *.bbl *.blg *.log *.pdf
