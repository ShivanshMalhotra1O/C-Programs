#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 12

int main()
{
    int pages[MAX_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames with -1 (empty)
    int pageFaults = 0;
    int counter = 0;
    int used[MAX_FRAMES] = {0}; // Keeps track of when each frame was used

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
                used[j] = counter++; // Update the usage counter for the frame
                break;
            }
        }

        // If page not found, replace the least recently used page
        if (found == 0)
        {
            int replaceIndex = 0;
            int leastUsed = used[0];

            // Find the least recently used page
            for (int j = 1; j < MAX_FRAMES; j++)
            {
                if (used[j] < leastUsed)
                {
                    leastUsed = used[j];
                    replaceIndex = j;
                }
            }

            // Replace the page at the replaceIndex with the current page
            frames[replaceIndex] = page;
            used[replaceIndex] = counter++; // Update the usage counter for the new frame
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
