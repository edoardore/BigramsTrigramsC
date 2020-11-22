# BigramsTrigramsC
Progetto finale di Parallel Computing, versione sequenziale.

## Utilizzo
Eseguire il file main.c per il programma in sequenziale, mentre per la versione in parallelo visitare la repo [BigramsTrigramsPThreads](https://github.com/edoardore/BigramsTrigramsPThreads).


## Esecuzione
Il programma leggerà i file all'interno della directory Gutenberg\txt e ne calcolerà i bigrammi ed i trigrammi.


## Esempio di output del file ```main.c```
```
aa: 439
ab: 104371
ac: 163436
...
zzi: 1362
zzl: 1147
zzo: 14
zzy: 94
zzz: 10
Tempo totale di esecuzione: ms 14059

Process finished with exit code 0
```

## Librerie utilizzate
```c
#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.


## License
[Edoardo Re](https://github.com/edoardore), 2020
