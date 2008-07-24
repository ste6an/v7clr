/*
1cheaders.inl
Данный файл содержит определения некоторых глобальных объектов,
практически всегда используемых в 1С-проектах, и несколько полезных
функций.
Автоматически подключает и необходимые lib'ы/
Лучше всего включить его в stdafx.cpp в нужных проектах
*/

// Сразу добавим упаковку сегментов
//#pragma comment(linker,"/FILEALIGN:512")

// Подключим либы
// Путь к либам должен задаватся от каталога текущего проекта, а не от каталога этого файла
// По умолчанию каталог проекта на одном уровне с каталогом 1CHeaders
// Если это не так, то перед включением 1cheaders.inl нужно определить нужный HEADER1C_PATH
#ifndef HEADER1C_PATH
	#define HEADER1C_PATH "../1cheaders"
#endif

#pragma comment (lib,HEADER1C_PATH "/libs/basic.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/bkend.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/blang.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/br32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/dbeng32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/editr.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/frame.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/moxel.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/rgproc.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/seven.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/txtedt.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/type32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/userdef.lib")