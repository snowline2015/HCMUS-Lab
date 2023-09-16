
import enchant
dic = enchant.Dict("en_US")
from copy import deepcopy

# from https://en.wikipedia.org/wiki/Letter_frequency
char_freq = ['e','t','a','o','i','n','s','h','r','d','l','c','u',
             'm','w','f','g','y','p','b','v','k','j','x','q','z']
copy_char_freq = deepcopy(char_freq)

txt = input('Input cipher text: ')
# Test case: NWVKIF UWVYC TWY AFYXAKIL CD QKIWCI UNVCCIKYEP HP EIK QEANLEDDL CDP IWKCE XDFP XDYIP. UNVCCIKYEP'Y AFACAWN LIYAMF, XVHNAYEIL DFNAFI HP UWVYC, KIUIKY CD EIK WY 'XDYIP' WY TINN. EIK QVCAI OWKG, CEKII XAFG WFL QPWF HVCCIKUNAIY, AY YAOANWK CD CEWC DU CEI XDFP YGP YGAOOIK.
# Expected output: lauren faust was inspired to create fluttershy by her childhood toy earth pony posey. fluttershy's initial design, published online by faust, refers to her as 'posey' as well. her cutie mark, three pink and cyan butterflies, is similar to that of the pony sky skimmer.


def count_char_freq(str):
    freq_count = {}
    for i in str:
        if i in freq_count:
            freq_count[i] += 1
        elif i.isalpha():
            freq_count[i] = 1
    return freq_count


txt_freq = [x for x in count_char_freq(txt).items()]
sorted_txt_freq_desc = sorted(txt_freq, key=lambda x: x[1], reverse=True)

print(sorted_txt_freq_desc)
print(char_freq)


def text_replace(text, char_replaced, char_replace):
    for i in sorted_txt_freq_desc:
        if i[0] == char_replaced:
            sorted_txt_freq_desc.remove(i)
    if char_replace in copy_char_freq:
        copy_char_freq.remove(char_replace)
    return text.replace(str(char_replaced), str(char_replace))


def check_rule(text):
    words_arr = text.split(" ")

    for i in words_arr:
        # rule 1: English contractions
        if i[len(i) - 2] == '\'':
            # Ex: Can'* : * should be 't'
            if i[len(i) - 3] == 'n':
                text = text_replace(text, i[len(i) - 1], 't')
            elif i[len(i) - 1] == 't':
                text = text_replace(text, i[len(i) - 3], 'n')

            # Ex: He'* : * should be 's' or 'd'
            if 's' in copy_char_freq:
                text = text_replace(text, i[len(i) - 1], 's')
            elif i[len(i) - 1].isupper():
                text = text_replace(text, i[len(i) - 1], 'd')

        if i[len(i) - 3] == '\'':
            # Ex: He'AA: WW should be 'll'
            if i[len(i) - 1] == i[len(i) - 2] and i[len(i) - 1].isupper() and i[len(i) - 2].isupper():
                text = text_replace(text, i[len(i) - 1], 'l')

            # Ex: You'AB: AB should be 're' or 've'
            # Ex: He'AB: AB should be 've'

        # rule 2: stand-alone character should be 'a' or 'i'
        if len(i) == 1 and i.isupper():
            if 'a' in copy_char_freq:
                text = text_replace(text, i, 'a')
            else:
                text = text_replace(text, i, 'i')

    return text


def check_correct_percentage(text):
    words_arr = text.split(" ")
    count = 0
    for i in words_arr:
        if str(i).islower() and dic.check(str(i)): count += 1
    return count / len(words_arr) * 100


def automata():
    temp = deepcopy(txt)
    removed_backup = []
    roll_back = 0
    i = None
    temp_index_rollback = None
    flag = False

    while True:
        temp = check_rule(temp)
        if check_correct_percentage(temp) >= 75:
            return temp

        while len(sorted_txt_freq_desc) != 0:
            if temp_index_rollback is not None:
                # if temp_index_rollback != len(copy_char_freq) - 1:
                removed_backup.append([sorted_txt_freq_desc[0][0], sorted_txt_freq_desc[0][1],
                                        copy_char_freq[temp_index_rollback + 1]])
                temp = text_replace(temp, sorted_txt_freq_desc[0][0], copy_char_freq[temp_index_rollback + 1])
                temp_index_rollback = None
                roll_back = 0
            else:
                removed_backup.append(
                    [sorted_txt_freq_desc[0][0], sorted_txt_freq_desc[0][1], copy_char_freq[0]])
                temp = text_replace(temp, sorted_txt_freq_desc[0][0], copy_char_freq[0])

        if check_correct_percentage(temp) >= 75:
            return temp


        while i != len(copy_char_freq):
            temp = temp.replace(str(removed_backup[len(removed_backup) - 1][2]),
                                str(removed_backup[len(removed_backup) - 1][0]))
            sorted_txt_freq_desc.insert(0, (str(removed_backup[len(removed_backup) - 1][0]),
                                            removed_backup[len(removed_backup) - 1][1]))
            copy_char_freq.append(str(removed_backup[len(removed_backup) - 1][2]))
            copy_char_freq.sort(key=lambda a: char_freq.index(a))

            i = deepcopy(copy_char_freq.index(str(removed_backup[len(removed_backup) - 1][2])))
            removed_backup.pop(len(removed_backup) - 1)

            removed_backup.append(
                [sorted_txt_freq_desc[0][0], sorted_txt_freq_desc[0][1], copy_char_freq[i + 1]])
            temp = text_replace(temp, sorted_txt_freq_desc[0][0], copy_char_freq[i + 1])

            if check_correct_percentage(temp) >= 75:
                return temp
            i += 1
            if i == len(copy_char_freq) or str(removed_backup[len(removed_backup) - 1 - roll_back][2]) == 'z':
                roll_back += 1

        i = None
        j = 0
        while j != roll_back + 1:
            temp = temp.replace(str(removed_backup[len(removed_backup) - 1][2]),
                                str(removed_backup[len(removed_backup) - 1][0]))
            sorted_txt_freq_desc.insert(0, (str(removed_backup[len(removed_backup) - 1][0]),
                                            removed_backup[len(removed_backup) - 1][1]))
            copy_char_freq.append(str(removed_backup[len(removed_backup) - 1][2]))
            copy_char_freq.sort(key=lambda a: char_freq.index(a))

            if j == roll_back:
                temp_index_rollback = deepcopy(copy_char_freq.index(str(removed_backup[len(removed_backup) - 1][2])))

            removed_backup.pop(len(removed_backup) - 1)

            if temp_index_rollback == len(copy_char_freq) - 1:
                roll_back += 1

            j += 1


print(automata())









