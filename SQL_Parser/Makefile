LEX = flex
YACC = bison
CC = g++ --std=c++11

SRC = Parser.tab.c lex.yy.c

TARGET = sql
LEXTARGET = lex.yy.c
YACCTARGET = Parser.tab.c Parser.tab.h

all : $(LEXTARGET) $(YACCTARGET) $(TARGET)

$(LEXTARGET) : Lexer.l
	$(LEX) Lexer.l

$(YACCTARGET) : Parser.y
	$(YACC) -d Parser.y

$(TARGET) : $(SRC)
	$(CC) $(SRC) -o $(TARGET)

clean :
	rm -rf $(LEXTARGET)
	rm -rf $(YACCTARGET)
	rm -rf $(TARGET)
