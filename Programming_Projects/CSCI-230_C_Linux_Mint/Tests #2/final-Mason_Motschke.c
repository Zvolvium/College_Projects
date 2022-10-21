// Mason Motschke - CSCI 230
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {char *word; struct node *next; } List;
typedef struct codex {char *word; char *correction; struct codex *next; } Codex;

void list_Add (List *head, char word[]){ // Works, as well as Done :)
  List *curr; curr = head->next; int wordlen;
  if (head->next == NULL){ // Adds first in list ---------------------\/
    head->next = (List*)malloc(sizeof(List)); wordlen = strlen(word) + 1; // gets len of words
    head->next->word = (char*)malloc(sizeof(wordlen));
    strcpy(head->next->word, word); head->next->next = NULL;
  } // ---------------------------------------------------------------^

  else { // If not adding first in list ----------------------\/
    while (curr->next != NULL){ curr = curr->next; }
    curr->next = (List*)malloc(sizeof(List)); curr = curr->next;
    wordlen = strlen(word) + 1; curr->word = (char*)malloc(sizeof(wordlen));
    strcpy(curr->word, word); curr->next = NULL;
  } // -------------------------------------------------------^
}

void codex_Add (Codex *head, char word[], char correction[]){ // Works, as well as Done :)
  Codex *curr; curr = head->next; int wordlen, corrlen;
  if (head->next == NULL){ // Adds first in codex -------------------------\/
    head->next = (Codex*)malloc(sizeof(Codex));
    wordlen = strlen(word) + 1; corrlen = strlen(correction) + 1; // gets len of words
    head->next->word = (char*)malloc(sizeof(wordlen));
    head->next->correction = (char*)malloc(sizeof(corrlen));
    strcpy(head->next->word, word); strcpy(head->next->correction, correction); head->next->next = NULL;
  } // --------------------------------------------------------------------^

  else { // If not adding first in codex --------------------\/
    while (curr->next != NULL){ curr = curr->next; }
    curr->next = (Codex*)malloc(sizeof(Codex)); curr = curr->next;
    wordlen = strlen(word) + 1; corrlen = strlen(correction) + 1;
    curr->word = (char*)malloc(sizeof(wordlen)); curr->correction = (char*)malloc(sizeof(corrlen));
    strcpy(curr->word, word); strcpy(curr->correction, correction); curr->next = NULL;
  } // ------------------------------------------------------^
}

void ReadData (List *head){ // Works, as well as Done :)
  FILE *data; data = fopen("finaldata.txt", "r");
  if (data == NULL){ printf("\nError: File 'finaldata.txt' Failed to Open!!\n"); fclose(data); exit(0); }
  printf("\n - Reading Data...\n"); size_t line_size = 0; char *line_buff = NULL, *token; // Buffer Setup
  while (1){
    // Use getline with strtok to seperate words within the line; look at hw7data.txt :)
    // Separate ',' and '.' from ends of words and add to linked list
    getline(&line_buff, &line_size, data); token = strtok(line_buff, " ");
    while (token != NULL){
      /*printf("Token: %s\n", token);*/
      list_Add(head, token);
      token = strtok(NULL, " \r\n"); // Makes sure strtok() doesn't get confused with end of line char
    }
    if (feof(data)){ fclose(data); break; }
  } printf("Data Read\n"); free(line_buff); line_buff = NULL; free(token); token = NULL;
}

void ReadCodex (Codex *head){ // Works, as well as Done :)
  FILE *codex; codex = fopen("finalcodex.txt", "r");
  if (codex == NULL){ printf("\nError: File 'finalcodex.txt' Failed to Open!!\n"); fclose(codex); exit(0); }
  printf("\n - Reading Codex...\n"); char word[100], correction[100]; // Buffer Setup
  while (1){
    fscanf(codex, "%s %s", word, correction); codex_Add(head, word, correction);
    if (feof(codex)){ fclose(codex); break; }
  } printf("Codex Read\n");
}
/*
void list_Add (List *head, char word[]){ // Works, as well as Done :)
  List *curr; curr = head->next; int wordlen;
  if (head->next == NULL){ // Adds first in list ---------------------\/
    head->next = (List*)malloc(sizeof(List)); wordlen = strlen(word) + 1; // gets len of words
    head->next->word = (char*)malloc(sizeof(wordlen));
    strcpy(head->next->word, word); head->next->next = NULL;
  } // ---------------------------------------------------------------^

  else { // If not adding first in list ----------------------\/
    while (curr->next != NULL){ curr = curr->next; }
    curr->next = (List*)malloc(sizeof(List)); curr = curr->next;
    wordlen = strlen(word) + 1; curr->word = (char*)malloc(sizeof(wordlen));
    strcpy(curr->word, word); curr->next = NULL;
  } // -------------------------------------------------------^
}

void codex_Add (Codex *head, char word[], char correction[]){ // Works, as well as Done :)
  Codex *curr; curr = head->next; int wordlen, corrlen;
  if (head->next == NULL){ // Adds first in codex -------------------------\/
    head->next = (Codex*)malloc(sizeof(Codex));
    wordlen = strlen(word) + 1; corrlen = strlen(correction) + 1; // gets len of words
    head->next->word = (char*)malloc(sizeof(wordlen));
    head->next->correction = (char*)malloc(sizeof(corrlen));
    strcpy(head->next->word, word); strcpy(head->next->correction, correction); head->next->next = NULL;
  } // --------------------------------------------------------------------^

  else { // If not adding first in codex --------------------\/
    while (curr->next != NULL){ curr = curr->next; }
    curr->next = (Codex*)malloc(sizeof(Codex)); curr = curr->next;
    wordlen = strlen(word) + 1; corrlen = strlen(correction) + 1;
    curr->word = (char*)malloc(sizeof(wordlen)); curr->correction = (char*)malloc(sizeof(corrlen));
    strcpy(curr->word, word); strcpy(curr->correction, correction); curr->next = NULL;
  } // ------------------------------------------------------^
}*/

void ParsePunctuation (List *head){ //                   Works, as well as Done :)
  // Parses and adds punctuation to own link in list
  List *curr = head->next; char word[100], temp[2]; int i, flag;
  while (curr->next != NULL){
    flag = 0; strcpy(word, curr->word);
    for (i = 0; i < strlen(word); i++){
      if ( (word[i] == ',') || (word[i] == '.') ){ // Removes punct from word--------\/
        temp[0] = word[i]; word[i] = '\0'; strcpy(curr->word, word);
        // --------------------------------------------------------------------------^

        List *node; node = (List*)malloc(sizeof(List)); node->next = curr->next; curr->next = node;
        node->word = (char*)malloc(sizeof(strlen(temp)) + 1); temp[1] = '\0'; strcpy(node->word, temp); flag = 1;
      } // Sets punct with own link in the list----------------------------------------^
    }
    if (flag == 0){ curr = curr->next; }
    else if (flag == 1){ curr = curr->next->next; }
    if (curr == NULL){ break; }
  } strcpy(word, curr->word);
  for (i = 0; i < strlen(word); i++){
    if ( (word[i] == ',') || (word[i] == '.') ){ // Removes punct from word-\/
      temp[0] = word[i]; word[i] = '\0'; strcpy(curr->word, word);
      // -------------------------------------------------------------------^

      List *node; node = (List*)malloc(sizeof(List)); node->next = curr->next; curr->next = node;
      node->word = (char*)malloc(sizeof(strlen(temp)) + 1); temp[1] = '\0'; strcpy(node->word, temp);
    } // Sets punct with own link in the list--------------------------------------------^
  }   // Punctuation is in string format!!!!!!!!!!!
}

void FreeAll (List *lhead, Codex *chead){ // Works, as well as Done :)
  // Frees Codex
  printf("\n - Freeing List and Codex...\n");
  Codex *ccurr = chead->next; Codex *cnext; free(chead); chead = NULL; // Free head, set NULL
  if (ccurr == NULL){ } // Do Nothing
  else {
  while (ccurr->next != NULL){ // Iterates over Linked List
    if (ccurr == NULL){ break; }
    cnext = ccurr->next; free(ccurr->word); free(ccurr->correction);// ---\/
    ccurr->word = NULL; ccurr->correction = NULL; // Free word+correction, set NULL
    free(ccurr); ccurr = cnext; // Free ccurr, iterate to next link
  } free(ccurr); ccurr = NULL; } // Free ccurr, set NULL

  // Frees List
  List *lcurr = lhead->next; List *lnext; free(lhead); lhead = NULL; // Free head, set NULL
  if (lcurr == NULL){ } // Do Nothing
  else {
  while (lcurr->next != NULL){ // Iterates over Linked List
    if (lcurr == NULL){ break; }
    lnext = lcurr->next; free(lcurr->word); lcurr->word = NULL; // Free word, set NULL
    free(lcurr); lcurr = lnext; // Free lcurr, iterate to next link
  } free(lcurr); lcurr = NULL; }  // Free lcurr, set NULL
  printf("List and Codex Freed\n\n"); cnext = NULL; lnext = NULL;
}

void ReplaceWords (List *lhead, Codex *chead, int *changed){ // Words, as well as Done :)
  // Replaces incorrect words w/ correct ones
  List *lcurr = lhead->next; Codex *ccurr = chead->next; printf("\n - Replacing Words...\n");
  while (lcurr != NULL){
    ccurr = chead->next;
    while (ccurr != NULL){
      if (strcmp(lcurr->word, ccurr->word) == 0){ // If words are same replace with correct word
        free(lcurr->word); lcurr->word = (char*)malloc(sizeof(ccurr->correction) + 1);
        strcpy(lcurr->word, ccurr->correction); *changed = *changed + 1;
      } ccurr = ccurr->next;
    } lcurr = lcurr->next;
  } printf("Word Replacing Complete\n\n");
}

void PrintPoem (List *lhead, int *deleted){ // Works, as well as Done :)
  // Prints Poem In the specified format
  printf(" - Printing Poem...\n\n"); List *lcurr = lhead->next; List *temp;
  while (lcurr != NULL){
    if ( (strcmp(lcurr->next->word, ".") == 0) || (strcmp(lcurr->next->word, ",") == 0)){
      printf("%s%s\n", lcurr->word, lcurr->next->word); lcurr = lcurr->next->next;
    }
    else if (strcmp(lcurr->next->word, "skip") == 0){ temp = lcurr->next; // Deletes skips to optimize list
      free(lcurr->next->word); lcurr->next = lcurr->next->next; free(temp); lcurr = lcurr->next;
      *deleted = *deleted + 1;
    } // skip case -----------------^
    else if ( (strcmp(lcurr->word, "P") == 0) && (strcmp(lcurr->next->word, "C") == 0) ){ // Fixed PC case
      printf("%s", lcurr->word); lcurr = lcurr->next;                                     // Displayed as "P C"
    }                                                                                     // Corrected to "PC"
    else {
      printf("%s ", lcurr->word); lcurr = lcurr->next;
    }
  } printf("\nPrinting Complete\n");
}

int main (void){
  Codex *codexHead; List *listHead; // Setup Heads -----------\/
  codexHead = (Codex*)malloc(sizeof(Codex)); listHead = (List*)malloc(sizeof(List));
  codexHead->next = NULL; listHead->next = NULL; // -----------^
  int *Deleted, *Changed;
  Deleted = (int*)malloc(sizeof(int)); Changed = (int*)malloc(sizeof(int));
  *Deleted = 0; *Changed = 0;
  ReadData(listHead); ReadCodex(codexHead); // Reads+Adds Data to Linked Lists <--------------------

  /* // This code is for displaying each linked list - Comment out all list look threws for final
  Codex *ccurr = codexHead->next; printf("\n-----------------------Codex----------------------\n"); int x = 1;
  while (ccurr != NULL){ // Print Codex----------^------------------\/
    printf("Word: %s - Correction: %s - x: %d\n", ccurr->word, ccurr->correction, x); ccurr = ccurr->next; x++; }

  */
  /*int size;
  List *lcurr = listHead->next; printf("\n------------------List Before-----------------------\n");
  while (lcurr != NULL){
    size = strlen(lcurr->word);
    printf("Word: %s - x: %d - Size: %d\n", lcurr->word, x, size); lcurr = lcurr->next; x++; }
  */

  ParsePunctuation(listHead); ReplaceWords(listHead, codexHead, Changed); PrintPoem(listHead, Deleted);
  printf("\nWords Changed: %d\nWords Removed: %d\n", *Changed, *Deleted);
  /*
  int x = 1; List *lcurr;
  lcurr = listHead->next; printf("\n-------------------List After-----------------------\n"); x = 1;
  while (lcurr != NULL){ // Print List-----------^------------------\/
    size = strlen(lcurr->word);
    printf("Word: %s - x: %d - Size: %d\n", lcurr->word, x, size); lcurr = lcurr->next; x++; }
  */
  free(Deleted); free(Changed);
  FreeAll(listHead, codexHead); return 0;
}
