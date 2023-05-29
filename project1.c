#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int *random_input_arr(int count);
int *sorted_arr(int count);
int *reverse_sorted_arr(int count);

void swap(int *a, int *b);

void insertion_sort(int arr[], int left, int right);

void merge_sort(int arr[], int left_index, int right_index);
void merge(int arr[], int left_index, int mid_index, int right_index);

void heap_sort(int arr[], int count);
void heap_insert(int heap[], int element, int *last_element);
int heap_remove_min(int heap[], int *last_element);

void quick_sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

void mod_quick_sort(int arr[], int left, int right);
int mod_partition(int arr[], int left, int right);

int main(){
    clock_t t;
    double time_spent, at_is, at_ms, at_hs, at_iqs, at_mqs;
    double max_is, max_ms, max_hs, max_iqs, max_mqs;
    double min_is, min_ms, min_hs, min_iqs, min_mqs;
    int count;
    int input_sizes[] = {1000, 2000, 3000, 5000, 10000, 20000, 30000, 40000, 50000, 60000};
    FILE *df;
    //FILE *rdf;

    df = fopen("data.txt", "w");
    //rdf = fopen("raw_data.txt", "w");

    srand(time(NULL));


    for(int i = 0; i < 10; i++){
        count = input_sizes[i];

        printf("Input Size: %d\n", count);

        fprintf(df, "Input Size: %d\n", count);
        //fprintf(rdf, "Input Size: %d\n", count);
        

        for(int j = 0; j < 3; j++){
            at_is = 0;
            at_ms = 0;
            at_hs = 0;
            at_iqs = 0;
            at_mqs = 0;
            
            max_is = DBL_MIN; 
            max_ms = DBL_MIN; 
            max_hs = DBL_MIN;
            max_iqs = DBL_MIN;
            max_mqs = DBL_MIN;

            min_is = DBL_MAX;
            min_ms = DBL_MAX;
            min_hs = DBL_MAX;
            min_iqs = DBL_MAX;
            min_mqs = DBL_MAX;

            for(int k = 0; k < 20; k++){
                printf("Iteration %d\n", k);
                //fprintf(rdf, "Iteration %d\n", j);
                int *base_arr;

                switch(j){
                    default:;
                    case 0:;
                        base_arr = random_input_arr(count);
                        break;
                    case 1:;
                        base_arr = sorted_arr(count);
                        break;
                    case 2:;
                        base_arr = reverse_sorted_arr(count);
                        break;
                }

                int unsorted_arr[count];

                memcpy(unsorted_arr, base_arr, count * sizeof(int));

                t = clock();
                insertion_sort(unsorted_arr, 0, count);
                t = clock() - t;
                time_spent = (double) t / CLOCKS_PER_SEC;
                at_is += time_spent;
                max_is = MAX(max_is, time_spent);
                min_is = MIN(min_is, time_spent);

                printf("Insertion-Sort took %f seconds to execute\n", time_spent);
                //fprintf(rdf, "Insertion-Sort took %f seconds to execute\n", time_spent);

                memcpy(unsorted_arr, base_arr, count * sizeof(int));

                t = clock();
                merge_sort(unsorted_arr, 0, count);
                t = clock() - t;
                time_spent = (double) t / CLOCKS_PER_SEC;
                at_ms += time_spent;
                max_ms = MAX(max_ms, time_spent);
                min_ms = MIN(min_ms, time_spent);

                printf("Merge-Sort took %f seconds to execute\n", time_spent);
                //fprintf(rdf, "Merge-Sort took %f seconds to execute\n", time_spent);

                memcpy(unsorted_arr, base_arr, count * sizeof(int));

                t = clock();
                heap_sort(unsorted_arr, count);
                t = clock() - t;
                time_spent = (double) t / CLOCKS_PER_SEC;
                at_hs += time_spent;
                max_hs = MAX(max_hs, time_spent);
                min_hs = MIN(min_hs, time_spent);

                printf("Heap-Sort took %f seconds to execute\n", time_spent);
                //fprintf(rdf, "Heap-Sort took %f seconds to execute\n", time_spent);

                memcpy(unsorted_arr, base_arr, count * sizeof(int));

                t = clock();
                quick_sort(unsorted_arr, 0, count);
                t = clock() - t;
                time_spent = (double) t / CLOCKS_PER_SEC;
                at_iqs += time_spent;
                max_iqs = MAX(max_iqs, time_spent);
                min_iqs = MIN(min_iqs, time_spent);

                printf("In-Place Quicksort took %f seconds to execute\n", time_spent);
                //fprintf(rdf, "In-Place Quicksort took %f seconds to execute\n", time_spent);

                memcpy(unsorted_arr, base_arr, count * sizeof(int));

                t = clock();
                mod_quick_sort(unsorted_arr, 0, count);
                t = clock() - t;
                time_spent = (double) t / CLOCKS_PER_SEC;
                at_mqs += time_spent;
                max_mqs = MAX(max_mqs, time_spent);
                min_mqs = MIN(min_mqs, time_spent);

                printf("Modified Quicksort took %f seconds to execute\n", time_spent);
                //fprintf(rdf, "Modified Quicksort took %f seconds to execute\n", time_spent);

                printf("\n");
                //fprintf(rdf, "\n");

                free(base_arr);
            }

            at_is /= 20;
            at_ms /= 20;
            at_hs /= 20;
            at_iqs /= 20;
            at_mqs /= 20;

            switch(j){
                default:
                case 0:;
                    printf("Randomly Generated Array: \n");
                    fprintf(df, "Randomly Generated Array: \n");
                    break;
                case 1:;
                    printf("Sorted Array: \n");
                    fprintf(df, "Sorted Array: \n");
                    break;
                case 2:;
                    printf("Reverse Sorted Array: \n");
                    fprintf(df, "Reverse Sorted Array: \n");
                    break;
            }

            printf("    Insertion-Sort: average: %fs, max: %fs, min:%fs\n", at_is, max_is, min_is);
            fprintf(df, "   Insertion-Sort: average: %fs, max: %fs, min:%fs\n", at_is, max_is, min_is);
            printf("    Merge-Sort: average: %fs, max: %fs, min:%fs\n", at_ms, max_ms, min_ms);
            fprintf(df, "   Merge-Sort: average: %fs, max: %fs, min:%fs\n", at_ms, max_ms, min_ms);
            printf("    Heap-Sort: average: %fs, max: %fs, min:%fs\n", at_hs, max_hs, min_hs);
            fprintf(df, "   Heap-Sort: average: %fs, max: %fs, min:%fs\n", at_hs, max_hs, min_hs);
            printf("    In-Place Quicksort: average: %fs, max: %fs, min:%fs\n", at_iqs, max_iqs, min_iqs);
            fprintf(df, "   In-Place Quicksort: average: %fs, max: %fs, min:%fs\n", at_iqs, max_iqs, min_iqs);
            printf("    Modified Quicksort: average: %fs, max: %fs, min:%fs\n", at_mqs, max_mqs, min_mqs);
            fprintf(df, "   Modified Quicksort: average: %fs, max: %fs, min:%f\n", at_mqs, max_mqs, min_mqs);

            printf("\n");
            fprintf(df, "\n");
            //fprintf(rdf, "\n");
        }
    }

    fclose(df);
    //fclose(rdf);

    return 0;
}

int *random_input_arr(int count){
    int *arr = (int*)malloc((count) * sizeof(int));
    for(int i = 0; i < count; i++)
        arr[i] = rand();
    return arr;
}

int *sorted_arr(int count){
    int *arr = (int*)malloc((count) * sizeof(int));
    for(int i = 0; i < count; i++)
        arr[i] = i;
    return arr;
}

int *reverse_sorted_arr(int count){
    int *arr = (int*)malloc((count) * sizeof(int));
    for(int i = 0; i < count; i++)
        arr[count - 1 - i] = i;
    return arr;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int arr[], int left, int right){
    for(int i = left + 1; i <= right; i++){
        for(int j = i; j > left && arr[j - 1] > arr[j]; j--){
            swap(&arr[j-1], &arr[j]);
        }
    }
}

void merge_sort(int arr[], int left_index, int right_index){
    if(left_index < right_index){
        int mid_index = (left_index + right_index)/2;
        merge_sort(arr, left_index, mid_index);
        merge_sort(arr, mid_index+1, right_index);
        merge(arr, left_index, mid_index, right_index);
    }
}

void merge(int arr[], int left_index, int mid_index, int right_index){
    int left_size, right_size, left_current_index, right_current_index, merge_index;

    left_size = mid_index - left_index + 1;
    right_size = right_index - mid_index;

    int left_arr[left_size], right_arr[right_size];

    for(int i = 0; i < left_size; i++){
        left_arr[i] = arr[left_index + i];
    }
    for(int i = 0; i < right_size; i++){
        right_arr[i] = arr[mid_index + 1 + i];
    }

    left_current_index = 0;
    right_current_index = 0;
    merge_index = left_index;

    while(left_current_index < left_size && right_current_index < right_size){
        if(left_arr[left_current_index] <= right_arr[right_current_index]){
            arr[merge_index] = left_arr[left_current_index];
            left_current_index++;
        } else {
            arr[merge_index] = right_arr[right_current_index];
            right_current_index++;
        }
        merge_index++;
    }

    while(left_current_index < left_size){
        arr[merge_index] = left_arr[left_current_index];
        left_current_index++;
        merge_index++;
    }

    while(right_current_index < right_size){
        arr[merge_index] = right_arr[right_current_index];
        right_current_index++;
        merge_index++;
    }

}

void heap_sort(int arr[], int count){
    int *heap = (int*)malloc((count+1) * sizeof(int));
    int last_element;
    
    last_element = 0;

    for(int i = 0; i < count; i++){
        heap_insert(heap, arr[i], &last_element);
    }

    for(int i = 0; i < count; i++){
        arr[i] = heap_remove_min(heap, &last_element);
    }
}

void heap_insert(int heap[], int element, int *last_element){
    (*last_element)++;
    heap[*last_element] = element;
    int i = *last_element;
    while(i > 1 && heap[i/2] > heap[i]){
        swap(&heap[i/2], &heap[i]);
        i /= 2;
    }
}

int heap_remove_min(int heap[], int *last_element){
    int temp = heap[1];
    heap[1] = heap[*last_element];
    (*last_element)--;
    int i = 1;
    while(i < *last_element){
        if(2*i + 1 <= *last_element){
            if(heap[i] <= heap[2*i] && heap[i] <= heap[2*i+1]){
                return temp;
            } else if (heap[2*i] <= heap[2*i + 1]){
                int j = 2*i;
                swap(&heap[i], &heap[j]);
                i = j;
            } else {
                int j = 2*i + 1;
                swap(&heap[i], &heap[j]);
                i = j;
            }
        } else {
            if(2*i <= *last_element){
                if(heap[i] > heap[2*i]){
                    swap(&heap[i], &heap[2*i]);
                }        
            }
            return temp;
        }
    }
    return temp;
}

void quick_sort(int arr[], int left, int right){
    if(left < right){
        int h;
        h = partition(arr, left, right);
        quick_sort(arr, left, h - 1);
        quick_sort(arr, h + 1, right);
    }
}

int partition(int arr[], int left, int right){
    int pivot, i, j;

    int random_index = left + rand() % (right - left + 1);
    swap(&arr[random_index], &arr[right]);
    
    pivot = arr[right];

    i = left - 1;

    for (j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void mod_quick_sort(int arr[], int left, int right){
    if(left < right){
        if(left + 15 <= right){
            int h;
            h = mod_partition(arr, left, right);
            mod_quick_sort(arr, left, h - 1);
            mod_quick_sort(arr, h + 1, right);
        } else 
            insertion_sort(arr, left, right);      
    }
}

int mod_partition(int arr[], int left, int right){
    int mid, pivot, i, j;

    mid = (left + (right - left)) / 2;
    if(arr[mid] < arr[left])
        swap(&arr[mid], &arr[left]);
    if(arr[right] < arr[left])
        swap(&arr[right], &arr[left]);
    if(arr[mid] < arr[right])
        swap(&arr[mid], &arr[right]);

    pivot = arr[right];

    i = left - 1;

    for (j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}