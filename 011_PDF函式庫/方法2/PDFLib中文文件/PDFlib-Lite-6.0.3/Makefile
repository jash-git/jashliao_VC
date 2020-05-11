# Main PDFlib Makefile
# $Id: Makefile,v 1.8.2.1 2005/01/04 12:00:43 rjs Exp $

top_builddir=.

include config/mkcommon.inc

SUB_DIRS = libs bind progs $(PTFDIR)

include config/mksubdirs.inc

# --------------------------- install ---------------------------------
install:: .dummy
	mkdir -p $(bindir)
	$(INSTALL) pdflib-config $(bindir)

# ----------------------- distclean ---------------------------------
distclean:: .dummy
	-$(RM) libtool pdflib-config config.cache config.log config.status \
	config/mkcommon.inc
