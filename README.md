# Загрузка работ на git.dozen.mephi.ru
Все работы необходимо загрузить на git.dozen.mephi.ru под своим аккаунтом до 25 января 18:00.

Для допуска к экзамену ВСЕ сданные вами работы должны быть загружены. Если вы не успели сдать все работы и собираетесь на пересдачу, загружайте только те что успели (перед пересдачей будет повторная проверка). Если вы планируете сдать работу позже перед экзаменом, загружайте предварительную версию, которую планируете показывать преподавателю.

Загружать наброски или несданные работы, выполненные менее чем на 60%, ни в коем случае НЕ НУЖНО.

Выгрузка работ будет проводиться программой, поэтому необходимо строго соблюдать следующий шаблон:
- название репозитория - только oop2023;
- внутри репозитория каталоги называются по номеру работы (1, 2, 3);
- внутри каждой из директорий должен лежать код только соответствующей работы;
- код из дополнительных заданий (прикладная программа в 2, динамическая загрузка в 3) загружать не нужно;
- если какой-то из работ нету, то каталог с этой работой не создавайте (или оставьте пустой);
- внутри каталогов с работами допускается наличие поддиректорий;
- все файлы исходного кода должны иметь расширение .c .h .cpp .hpp .tcc .cc .c++ или .cxx;
- вместе с файлами исходного кода допускается наличие прочих файлов (исходные данные, рисунки, файлы автосборки), которые имеют расширение строго НЕ из списка, приведенного выше; эти файлы не будут участвовать в проверке на плагиат;
- в репозитории должны отсутствовать большие файлы (размер одной ЛР не должен превышать 10MB);
- в репозитории должны отсутствовать чужие исходные коды (если пользуетесь CMake, ОБЯЗАТЕЛЬНО удаляйте директорию cmake-build-debug, так как в ней есть свои исходники);
- для продвинутых: допускается использование сабмодулей для аггрегации кода в одном репозитории или из сторонних систем контроля версий.

Внимание!!! Для самостоятельной проверки правильности загрузки работы рекоммендуется использовать следующую команду на сервере samos.dozen.mephi.ru:
```bash
check_oop_labs.sh <Путь к каталогу репозитория>
```
Например:
```bash
check_oop_labs.sh ~/oop2023
```

Шаблон для репозитория: https://git.dozen.mephi.ru/sodmitriev/oop2023, его можно скопировать или использовать в качестве шаблона чтобы точно не ошибиться.

Любые отклонения от шаблона эквивалентны отсутствию работы. Ошибочная загрузка не той работы также эквивалентна её отсутствию.

Проверка на плагиат выполняется программой с использованием нетривиальных алгоритмов, поэтому большинство методов сокрытия плагиата (изменение имен переменных, перестановка функций) ни коим образом не затруднят работу программы и не изменят результаты проверки. После получения отчета от программы, проверка всех подозрительных кейсов обязательно выполняется преподавателем, который в последствии принимает конечное решение.

Перечень работ (названия директорий): 1, 2, 3.