int main() {
        char placeholder = ' ';
        char result[15];
        char word[15] = "Ivanov        ";
        int count_placeholders = 0;
        int count_letters = 0;
    

        for (int i = 0; i < 15; i++)
        {
            if (word[i] == placeholder)
                count_placeholders++;
            else
                count_letters++;
        }
        count_letters--;
        int before = (int)count_placeholders / 2;
        for (int i = 0, n = 0; i < 15; i++)
        {
            if (before)
            {
                result[i] = placeholder;
                before--;
            }
            else if (count_letters)
            {
                result[i] = word[n++];
                count_letters--;
            }
            else
            {
                result[i] = placeholder;
            }
        }
        return  0;
    }
