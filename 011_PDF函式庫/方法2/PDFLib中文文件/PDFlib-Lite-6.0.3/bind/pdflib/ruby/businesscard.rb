#!/usr/bin/ruby
#
# $Id: businesscard.rb,v 1.1.2.7 2006/01/17 23:19:43 rjs Exp $
#
# PDFlib client: bussinescard example in Ruby
#

require 'PDFlib'

# This is where font/image/PDF input files live. Adjust as necessary.
#
# Note that this directory must also contain the LuciduxSans font
# outline and metrics files.
infile = "boilerplate.pdf"
searchpath = "../data"
data = {
  "name" =>                   "Victor Kraxi",
  "business.title" =>         "Chief Paper Officer",
  "business.address.line1" => "17, Aviation Road",
  "business.address.city" =>  "Paperfield",
  "business.telephone.voice"=>"phone +1 234 567-89",
  "business.telephone.fax" => "fax +1 234 567-98",
  "business.email" =>         "victor@kraxi.com",
  "business.homepage" =>      "www.kraxi.com"
}

begin
  p = PDFlib.new
  if (p.begin_document("businesscard.pdf", "") == -1)
      print "Error: " + p.get_errmsg()
  end

  # Set the search path for fonts and PDF files 
  p.set_parameter("SearchPath", searchpath)

  p.set_info("Creator", "businesscard.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "PDFlib block processing sample (Ruby)")

  blockcontainer = p.open_pdi(infile, "", 0)
  if (blockcontainer == -1)
    print "Error: " + p.get_errmsg()
  end

  page = p.open_pdi_page(blockcontainer, 1, "")
  if (page == -1)
    print "Error: " + p.get_errmsg()
  end

  p.begin_page_ext(20, 20, "");              # dummy page size

  # This will adjust the page size to the block container's size.
  p.fit_pdi_page(page, 0, 0, "adjustpage")

  # Fill all text blocks with dynamic data
  data.each { |key, value|
    if (p.fill_textblock(page, key, value,
	"embedding encoding=winansi") == -1)
      print "Warning: " + p.get_errmsg
    end
  }

  p.end_page_ext("")
  p.close_pdi_page(page)

  p.end_document("")
  p.close_pdi(blockcontainer)

rescue  PDFlibException => pe
  print "PDFlib exception occurred in businesscard sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
end

# vim: sw=2
