#!/usr/bin/ruby
#
# $Id: hello.rb,v 1.2.8.9 2006/01/16 12:00:27 rjs Exp $
#
# PDFlib client: hello example in Ruby
#

require 'PDFlib'

begin
  p = PDFlib.new

  if (p.begin_document("hello.pdf", "") == -1)
    raise  "Error: " + p.get_errmsg
  end

  p.set_info("Creator", "hello.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "Hello world (Ruby)!")

  p.begin_page_ext(595, 842, "")

  font = p.load_font("Helvetica-Bold", "winansi", "")

  p.setfont(font, 24)

  p.set_text_pos(50, 700)
  p.show("Hello world!")
  p.continue_text("(says Ruby)")
  p.end_page_ext("")

  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred in hello sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
end

# vim: sw=2
