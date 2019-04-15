////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// ARCHIVO CPP /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FBullCowGame.h" /// Incluimos el archivo de tipo cabecera
#include <map>
#define TMap std::map; 
/// Unreal String type and int type
using FString = std::string;
using int32   = int;

/// Constructor, llamamos a la función Reset();
FBullCowGame::FBullCowGame()
{
	Reset();
}

/// Reset() function, inicializamos dos constantes:
	///	- Número máximo de intentos
	///	- Palabra a adivinar
void FBullCowGame::Reset() 
{
	/// Variables constantes
	const     FString HIDDEN_WORDS = "arena";
	constexpr int32   MAX_TRIES    =		6;
	
	/// Inicialización de términos
	myCurrentTry =            1;
	myMaxtries   =    MAX_TRIES;
	myHiddenWord = HIDDEN_WORDS;

	return; 
}

/// Función de tipo int, devuelve el número máximo de intentos
int32 FBullCowGame::GetMaxTries()        const { return myMaxtries;   }

/// Función de tipo int, devuelve el intento actual
int32 FBullCowGame::GetCurrentTry()      const { return myCurrentTry; }

/// Retorna true si ha adivinado la palabra
bool  FBullCowGame::IsGameWon()				   { return false;		  }

/// Retorna la palabra la palabra 
FString FBullCowGame::GetHiddenWord()    const { return myHiddenWord; }

/// Check if there are repeated letters in the answer
bool FBullCowGame::GuessIsogram(FString guess)
{
#pragma region Opción 1

	for (int32 i = 0; i < guess.length(); i++)
	{
		char a = guess[i];
		
		for (int32 j = 0; j < guess.length(); j++)
		{
			char b = guess[j];

			if (a == b && i != j)
				return true;
		}
	}

#pragma endregion

#pragma region Opción 2 using std::map
/*
	std::map<char, bool> LetterSeen;

	for (auto Letter : guess)
	{
		Letter = tolower(Letter);

		if(LetterSeen[Letter])
			return false;
		else
			LetterSeen[Letter] = true;
	}
*/

#pragma endregion

	return false;
}

/// Check if the answer is not lower case
bool FBullCowGame::LowerCase(FString guess)
{
	for (int32 i = 0; i < guess.length(); i++)
	{
		char a = guess[i];

		if (isupper(a))
			return true;
	}
	return false;
}

/// Check if the anwer is a number 
bool FBullCowGame::NotLetters(FString guess)
{
	for (int32 i = 0; i < guess.length(); i++)
	{
		char a = guess[i];

		if (isdigit(a))
			return true;
	}

	return false;
}

/// Comprueba si la palabra introducida es válida
EGuessStatus FBullCowGame::CheckGuessValidity(FString guess)
{
	if (GuessIsogram(guess)) /// Not Isogram, guess not valid
	{
		return EGuessStatus::Not_Isogram;
	}
	if (LowerCase(guess)) /// Not all letters are lower case
	{
		return EGuessStatus::Not_LowerCase;
	}
	if (guess.length() != GetHiddenWord().length()) /// Wrong length
	{ 
		return EGuessStatus::Wrong_Length; 
	}
	if (NotLetters(guess)) /// Wrong length
	{
		return EGuessStatus::Not_Letters;
	}
	else
	{
		return EGuessStatus::OK;
	}

	//return (guess.length() == GetHiddenWord().length()) ?  false : true;
}

/// Recieves a valid guess, increments turn
FBullCowCount FBullCowGame::SumitGuess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount; 	

	/// Loop through all letter in hidden word
	for (int32 i = 0; i < myHiddenWord.length(); i++)
	{
		/// Loop through all letter in guessed word 
		for (int32 j = 0; j < guess.length(); j++)
		{	
			char a = myHiddenWord[i];
			char b = guess[j];

			if (a == b)
			{
				if (i == j)
					bullCowCount.Bulls++;

				if (i != j)
					bullCowCount.Cows++;
			}
		}	
	}

	return bullCowCount;
}
