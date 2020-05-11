#include<fstream>
#include<string>
#include<ctype.h>
#include <iostream>
#define _TABSIZE	4

using namespace std;

int tabsize = _TABSIZE;

class token {
public:
	token() : _what(code) {}
protected:
	enum type {code, comment, pp, keyword};
	string _str;
	type _what;
	friend istream& operator>>(istream&, token&);
	friend ostream& operator<<(ostream&, const token&);
};

bool iskeyword(const string& s)
{
	static const char* keywords[] = {
		"and",
		"and_eq",
		"asm",
		"auto",
		"bitand",
		"bitor",
		"bool",
		"break",
		"case",
		"catch",
		"char",
		"class",
		"compl",
		"const",
		"const_cast",
		"continue",
		"default",
		"delete",
		"do",
		"double",
		"dynamic_cast",
		"else",
		"enum",
		"explicit",
		"export",
		"extern",
		"false",
		"float",
		"for",
		"friend",
		"goto",
		"if",
		"inline",
		"int",
		"long",
		"mutable",
		"namespace",
		"new",
		"not",
		"not_eq",
		"operator",
		"or",
		"or_eq",
		"private",
		"protected",
		"public",
		"register",
		"reinterpret_cast",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",
		"static_cast",
		"struct",
		"switch",
		"template",
		"this",
		"throw",
		"true",
		"try",
		"typedef",
		"typeid",
		"typename",
		"union",
		"unsigned",
		"using",
		"virtual",
		"void",
		"volatile",
		"wchar_t",
		"while",
		"xor",
		"xor_eq"
	};

	for (int i = 0; i < sizeof(keywords) / sizeof(char*); i++)
		if (string(keywords[i]) == s)
			return true;

	return false;
}

bool containspp(const string& s)
{
	static const char* pptokens[] = {
		"define",
		"elif",
		"else",
		"endif",
		"error",
		"if",
		"ifdef",
		"ifndef",
		"include",
		"line",
		"pragma",
		"undef"
	};

	for (int i = 0; i < sizeof(pptokens) / sizeof(char*); i++)
		if (s.find(pptokens[i]) != string::npos)
			return true;

	return false;
}

istream& operator>>(istream& is, token& t)
{
	t._str = "", t._what = token::code;
	int c = is.get();
	switch (c) {
		case '/':
			c = is.get();
			if (c == '*') {
				t._str = "/*";
				t._what = token::comment;
				while (1) {
					c = is.get();
					if (c == EOF)
						return is.unget(), is.clear(), is;
					if (c == '/') {
						if (t._str.length() > 2 &&
							t._str[t._str.length() - 1] == '*') {
							return t._str += '/', is;
						}
					}
					t._str += (char)c;
				}
			} else if (c == '/') {
				t._str = "//";
				t._what = token::comment;
				c = is.get();
				while (c != '\n' && c != EOF) {
					t._str += (char)c;
					c = is.get();
				}
				if (c == '\n') {
					t._str += '\n';
				}
				return is;
			}
			t._str = '/';
			return is.unget(), is.clear(), is;
		case '#':
			t._str = '#';
			c = is.get();
			while (strchr(" \r\n\t", c)) {
				t._str += (char)c;
				c = is.get();
			}
			if (c == EOF)
				return is.unget(), is.clear(), is;
			while (strchr("abcdefghijklmnopqrstuvwxyz", c)) {
				t._str += (char)c;
				c = is.get();
			}
			is.unget(), is.clear();
			if (containspp(t._str))
				t._what = token::pp;
			return is;
		case '\'':
		case '"': {
			char q = (char)c;
			t._str = q;
			while (1) {
				c = is.get();
				if (c == EOF)
					return is.unget(), is.clear(), is;
				if (c == q) {
					if (t._str.length() >= 2) {
						if (!(t._str[t._str.length() - 1] == '\\' &&
							t._str[t._str.length() - 2] != '\\'))
							return t._str += q, is;
					} else {
						return t._str += q, is;
					}
				}
				t._str += (char)c;				
			}
		}
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'i':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
			t._str += (char)c;
			c = is.get();
			while (isalpha(c) || isdigit(c) || c == '_') {
				t._str += (char)c;
				c = is.get();
			}
			is.unget(), is.clear();
			if (iskeyword(t._str))
				t._what = token::keyword;
			return is;
		case EOF:
			return is;
		default:
			t._str += (char)c;
			c = is.get();
			while (c != '/' && c != '#' && !strchr("abcdefgilmnoprstuvwx", c) &&
				c != '\'' && c != '"' && c != EOF) {
				t._str += (char)c;
				c = is.get();
			}
			is.unget(), is.clear();
			return is;
	}
}

string html(const string& s)
{
	string s1;
	string::size_type i;
	for (i = 0; i < s.length(); i++) {
		switch (s[i]) {
			case '&':
				s1 += "&amp;";
				break;
			case '<':
				s1 += "&lt;";
				break;
			case '>':
				s1 += "&gt;";
				break;
			case '"':
				s1 += "&quot;";
				break;
			case '\t':
				s1.append(tabsize, ' ');
				break;
			default:
				s1 += s[i];
		}
	}
	return s1;
}

ostream& operator<<(ostream& os, const token& t)
{
	if (t._what == token::code)
		cout << html(t._str);
	else if (t._what == token::comment)
		cout << "<span class=comment>" << html(t._str) << "</span>";
	else if (t._what == token::keyword)
		cout << "<span class=keyword>" << html(t._str) << "</span>";
	else if (t._what == token::pp)
		cout << "<span class=pp>" << html(t._str) << "</span>";
	else
		cout << html(t._str);
	return os;
}

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3) {
		cout << "usage: cpphtml file [tab size]" << endl;
		return 0;
	}
	ifstream is(argv[1]);
	if (!is.good()) {
		cerr << "bad input file" << endl;
		return -1;
	}
	if (argc == 3) {
		tabsize = atoi(argv[2]);
		if (tabsize <= 0)
			tabsize = _TABSIZE;
	}
	cout << "<html>" << endl << "<head>" << endl << "<style>" << endl;
	cout << ".keyword{color:rgb(0,0,255);}" << endl;
	cout << ".comment{color:rgb(0,128,0);}" << endl;
	cout << ".pp{color:rgb(0,0,255);}" << endl;
	cout << "</style>" << endl << "<body>" << endl;
	cout << "<pre style=\"font-family:courier;font-size:10pt\">";
	token t;
	while (is >> t) {
		cout << t;
	}
	cout << "</pre>" << "</body>" << endl << "</html>" << endl;
	return 0;
}

