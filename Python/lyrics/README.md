# Song Genre Classification

## Introduction

Music genre help listeners comb through an almost endless amount of music to find songs that they enjoy. There are lots of factors that go into deciding what genre a piece of music falls into. Some of these factors include rthyem, tempo, lyrics, and artist. Given this, we were interested in seeing whether a song's genre can be identified by its lyrics alone. Also, since genre is a fluid concept and some songs fall into multiple genres, we want to see how many genre groups an unsupervised learning method think exists.

## Data Collection and Cleaning

In order to answer this question we needed lots of song lyrics with a genre associated with each song. To do this we used [genius' api](https://docs.genius.com/) which contains a wide variety of song lyrics from almost every possible genre. Since there are so many genres and even more sub-genres we decided to choose the five main genres according to Genius to see if our model could distinguish between just those five. The genres we selected were country, rock, rap, rhythm and blues, and pop. To select songs for these five genres we looked up the top artists in each genre and pulled their top 50 songs, if they had that many. If an artist was in two different genres we threw them out all together. In the end the number of songs per each genre were


| Genre  | Counts |
| ------------- | ------------- |
| Country  | 2,419  |
| Rock  | 3,277  |
| Rap  | 2,650  |
| Rhythm and Blues  | 2,388  |
| Pop  | 1,300  |


In order to make the data useable we had to do some cleaning and preprocessing. The first thing we did was remove formating, punctuation, and a tag that was included at the end of each song. Next we removed stop words and lematized the words. Lematizing takes words like start started starting and converts them into the base word, in this case start. Next we tokenized the lyrics so they would be in a format that is useable. We had two methods for doing this. The first method was to count vectorize each word. That created a dataframe in which each row was a song and each column was a word in the dataframe with a count of how many times that word appeared in the song.

The second mehtod used a Tf-idf score. This produces something similar to the first method but instead of a count is now gives each word a weight based on the words frequency in other documents.

Both methods were explored while creating the model. 


## EDA

The follwing tables show the five most common words for each genre, excluding words that don't carry a lot of meaning.

<table>
<tr><th>Country </th><th>Pop</th><th>Rock</th><th>Rhythm and Blues</th><th>Rap</th></tr>
<tr><td>

| Word  | Counts |
| ------------- | ------------- |
| Love  | 3,716  |
| Baby  | 2,798  |
| Time  | 2,645  |
| Girl  | 2,455  |
| Little  | 2,181  |
  
</td><td>  

| Wod  | Counts |
| ------------- | ------------- |
| Love  | 4,324  |
| Baby  | 2,482  |
| Want  | 1,845  |
| Wanna  | 1,702  |
| Say  | 1,659  |
  
</td><td> 

| Word  | Counts |
| ------------- | ------------- |
| Love  | 4,927  |
| Time  | 3,124  |
| Come  | 2,877  |
| Want  | 2,522  |
| See  | 2,501  |

</td><td>

| Word  | Counts |
| ------------- | ------------- |
| Love  | 11,976  |
| Baby  | 7,442  |
| Time  | 3,539  |
| Want  | 3,332  |
| Come  | 3,225  |

</td><td>

| Word  | Counts |
| ------------- | ------------- |
| N****  | 17,797  |
| B****  | 11,546  |
| F***  | 7,819  |
| S***  | 7,487  |
| Love  | 4,592  |

</td></tr> </table> 

## Methods and Results

When it came to choosing a model we looked at 12 different models and split the data into a train and test set. The following graph shows how each of the models performed when trying to predict on the test set.

![ModelPerformance](Images/Model-Performance-Graph.JPG)

The logistic regression model performed the best but we decided to use the random forest model. The reasoning behind this decision is that much of the interpretability associated with a logistic regression model is lost once you have more than two classes and it gets even worse once you have a lot of predictors, and although random forest models aren't particullary intrepretable they do allow us to look at which variables are the most important. Below is the list of words we found most important:

| Rank Of Importance  | Word |
| ------------- | ------------- |
| 1  | nice |
| 2  | frozen  |
| 3  | birthday  |
| 4  | ship  |
| 5  | ba  |
| 6  | louder  |
| 7  | gold  |
| 8  | wallet  |
| 9  | electric  |
| 10  | f***  |

When it comes to seeing which genres are easiest to predict, it is most helpful to look at a confusion matrix. The confusion matrix below shows the percentage of the genre predicted in each class.

![ConfusionMatrix](Images/Confusion-Matrix.JPG)

The genre that was predicted with the greatest accuaracy was rap. However our model did especially poor at predicting pop. Rock was often cofused with Country, Pop, and Rythem and Blues. 

When we turned to unsupervised method to determine how many genre there should be a kmeans clustering algorithm didn't produce a clear answer as can be seen below.

![Clustering](Images/Num-Of-Clusters.JPG)

When we tell the kmeans algorithm that there should be five groups it associated these words with each group

| Group  | Words |
| ------------- | ------------- |
| 1  | time come night never see take girl right say make |
| 2  | baby love come time want wanna need girl take say  |
| 3  | n**** b**** f*** s*** ayy gon money em wanna huh  |
| 4  | love want baby heart need never feel say time wanna  |
| 5  | la na ah da tell feel love song want  |

With the exception of group 3 it is hard to distinguish which group belongs to which genre.

## Limitations

There were some limitations to our project. One of the main limitations was assigning artists to genres. The genius API was great for pulling songs from an artist but the method to pull songs from a genre tag was very limited; there would've been only around 1500 songs total and country would have only included about 20. So when we decided to scrape songs from the top artists in each genre it created some concern. Some artists are in different genres and some songs might be considered one genre and some songs a different genre. But when we pulled their songs it all went to the same genre.

Another limitation was the date range for our songs. Our artists cover a large time range except for pop which is mostly the 21st century. Because genre's change and reinvent themselves over time, it might make it more difficult to define the cluster. Pulling songs from the same year might make identfying genre easier.

## Conclusion

In conclusion it appears that songs can, for the most, be separated into genre just based on their lyrics. Rap was the only genre that was largely identifiable. However, some genres are more similar that other genres. Rock, rhythm and blues, and pop were the genres that had the most misclassification. 

We feel that although lyrics is probably the most important feature, it likely isn't the only feature. Some extra variables that we could look at when trying to distinguish what genre music belongs to, is song length, word count, music key, number of featured artists, types of notes, and when the song was released. We believe that if we took some of these variables into account that we could get a much better accuaracy. 
