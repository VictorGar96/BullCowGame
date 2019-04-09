////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// ARCHIVO CPP /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FBullCowGame.h" /// Incluimos el archivo de tipo cabecera

/// Unreal String type and int type
using FString = std::string;
using int32   = int;

/// Constructor, llamamos a la funci�n Reset();
FBullCowGame::FBullCowGame()
{
	Reset();
}

/// Reset() function, inicializamos dos constantes:
	///	- N�mero m�ximo de intentos
	///	- Palabra a adivinar
void FBullCowGame::Reset() 
{
	
	/// Variables constantes
	const     FString HIDDEN_WORDS = "ant";
	constexpr int32   MAX_TRIES    =     3;

	
	/// Inicializaci�n de t�rminos
	myCurrentTry =            1;
	myMaxtries   =    MAX_TRIES;
	myHiddenWord = HIDDEN_WORDS;

	return; 
}

/// Funci�n de tipo int, devuelve el n�mero m�ximo de intentos
int32 FBullCowGame::GetMaxTries()        const { return myMaxtries;   }

/// Funci�n de tipo int, devuelve el intento actual
int32 FBullCowGame::GetCurrentTry()      const { return myCurrentTry; }

/// Retorna true si ha adivinado la palabra
bool  FBullCowGame::IsGameWon()  
{

	return false;
}

/// Retorna la palabra la palabra 
FString FBullCowGame::GetHiddenWord()    const { return myHiddenWord; }

/// Comprueba si la palabra introducida es v�lida
bool  FBullCowGame::CheckGuessValidity(FString guess)
{
	return (guess.length() == GetHiddenWord().length()) ?  false : true;
}


/// Recieves a valid guess, increments turn
FBullCowCount FBullCowGame::SumitGuess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount; 	

	for (int32 i = 0; i < myHiddenWord.length(); i++)
	{
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
