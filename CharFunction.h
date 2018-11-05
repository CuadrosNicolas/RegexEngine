/**
 * @brief
 * File regrouping all the function to identify a type of a character
 */
#pragma once


/**
 * @brief
 * Test if a character is a upper case letter
 * @param c char to test
 * @return true if the character is a upper case letter
 * @return false if the character is not a upper case letter
 */
bool upperCase(char c);
/**
 * @brief
 * Test if a character is a lower case letter
 * @param c char to test
 * @return true if the character is a lower case letter
 * @return false if the character is not a lower case letter
 */
bool LowerCase(char c);
/**
 * @brief
 * Test if a character is a  letter
 * @param c char to test
 * @return true if the character is a letter
 * @return false if the character is not a  letter
 */
bool Letter(char c);
/**
 * @brief
 * Test if a character is a letter, a number or a underscore
 * @param c char to test
 * @return true if the character is a letter, a number or a underscore
 * @return false if the character is not letter, a number or a underscore
 */
bool Word(char c);
/**
 * @brief
 * Test if a character is a  number
 * @param c char to test
 * @return true if the character is a number
 * @return false if the character is not a  number
 */
bool Number(char c);
/**
 * @brief
 * Test if a character is a  whitespace
 * @param c char to test
 * @return true if the character is a whitespace
 * @return false if the character is not a  whitespace
 */
bool WhiteSpace(char c);
/**
 * @brief
 * Set a character to lower case if a upper case letter
 * @param c character to change
 * @return char lower case character
 */
char ToLower(char c);
/**
 * @brief
 * Set a character to upper case if a lower case letter
 * @param c character to change
 * @return char upper case character
 */
char ToUpper(char c);