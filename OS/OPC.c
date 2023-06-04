#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 12

int main()
{
    int pages[MAX_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames with -1 (empty)
    int pageFaults = 0;

    for (int i = 0; i < MAX_PAGES; i++)
    {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == page)
            {
                found = 1;
                break;
            }
        }

        // If page not found, replace a page using Optimal Page Replacement algorithm
        if (found == 0)
        {
            int replaceIndex = -1;
            int farthest = i + 1;

            // Find the page that will not be used for the longest period of time
            for (int j = 0; j < MAX_FRAMES; j++)
            {
                int k;
                for (k = i + 1; k < MAX_PAGES; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        if (k > farthest)
                        {
                            farthest = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }

                // If a page is not referenced in the future, replace it
                if (k == MAX_PAGES)
                {
                    replaceIndex = j;
                    break;
                }
            }

            // Replace the page at the replaceIndex with the current page
            frames[replaceIndex] = page;
            pageFaults++;
        }

        // Print the current state of frames after each page reference
        printf("Page %d: ", page);
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
