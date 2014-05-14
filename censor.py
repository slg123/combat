#!/usr/bin/env python

def censor( text, word ):
    censored_list = []
    for i in text.split():
        if i == word:
            censored_word = []
            for char in word:
                censored_word.append( "*" )
            print ''.join( censored_word )
            censored_list.append( ''.join( censored_word ) )
        else:
            censored_list.append( i )
    return ' '.join( censored_list )

string = "this is a sentence this is"
word = "this"
print censor( string, word )

string = "hey hey hey hey"
word = "hey"
print censor( string, word )
print censor( "hey hey hey", "hey" )

    

