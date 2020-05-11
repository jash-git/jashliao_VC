# Makefile for PDFlib's Ruby binding
# $Id: Makefile,v 1.11.4.5 2005/12/23 12:54:55 rjs Exp $

top_builddir	= ../../..

include $(top_builddir)/config/mkcommon.inc

INCLUDES	= $(PDFLIBINC) $(RUBYINCLUDE)
# special CFLAGS, as -ansi is not working here.
PDFWALL		=
CFLAGS          = $(DEFS) $(DEFINES) $(INCLUDES)

LANG_LIBDIR 	= $(libdir)
BINDEXTERNALLIBS= $(RUBYLINK)

LIBNAME		= PDFlib$(LA)
OBJ		= pdflib_ruby$(LO)
SRC		= pdflib_ruby.c

include $(top_builddir)/config/mkbind.inc

test:: $(LIBNAME)
	@-if test -f .libs/PDFlib.dylib; then  	\
	  cp .libs/PDFlib.dylib PDFlib.bundle;		\
	else						\
	  cp .libs/PDFlib.so PDFlib.so;			\
	fi
	-$(RUBY) hello.rb
	-$(RUBY) image.rb
	-$(RUBY) pdfclock.rb
	-$(RUBY) invoice.rb
	-$(RUBY) businesscard.rb
	-$(RUBY) quickreference.rb

smoke:: test

install:: $(LIBNAME)
	$(LIBTOOL) --mode=install \
		$(INSTALL_DATA) $(LIBNAME) $(LANG_LIBDIR)

uninstall::
	$(LIBTOOL) --mode=uninstall $(RM) $(LANG_LIBDIR)/$(LIBNAME)

clean::
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf
	$(RM) smoke_c*.trace smoke_c*.pdf
	$(RM) PDFlib.so

distclean::

