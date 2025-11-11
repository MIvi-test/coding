#include <stdio.h>
#include <stdlib.h>

/**
 * \file doxygen_comments.c
 * \brief Пример Doxygen-совместимых комментариев в C.
 *
 * Эти комментарии используют стандартный синтаксис C (/* ... / и //),
 * но оформлены так, чтобы их распознавали инструменты документирования вроде Doxygen.
 */

/** \brief Складывает два целых числа.
 *  \param a Первое слагаемое
 *  \param b Второе слагаемое
 *  \return Сумма a и b
 */
static int add(int a, int b) {
    return a + b; ///< Короткое пояснение к возвращаемому выражению
}

/** \brief Точка входа программы.
 *  \return Код завершения (0 при успехе)
 */
int main(void) {
    int result = add(10, 32); //!< Однонострочный поясняющий комментарий
    printf("Result = %d\n", result);
    return EXIT_SUCCESS; ///< Успешное завершение
}
