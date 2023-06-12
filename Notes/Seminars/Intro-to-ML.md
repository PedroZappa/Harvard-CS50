# [Seminars](/README.md): Intro to ML

##### (Kevin and Zad)

___

## `Table o'Contents`

* [What is ML?](#what-is-ml)
* [Resources](#resources)

___

# `What is ML?`

![](/IMG/Seminar-ML/0.png)

___

## `Supervised Learning`

Given some `labeled data`, how can machines `learn to predict labels` that `generalize to unseen data`?

## `Unsupervised Learning`

Given some `unlabeled data`, how can machines `learn to find useful patterns` or `generalizations`?

![](/IMG/Seminar-ML/1.png)
___

## `General Outline in ML project Data Collection`

![](/IMG/Seminar-ML/2.png)

___

## `Hands-on example`

https://tinyurl.com/ML-notebook-1 

Save a copy before you edit!

___

## `For CS50 final project`

![](/IMG/Seminar-ML/3.png)

___

## `Coding Environment`

`Jupyter Notebook`:
* Deepnote
* VSCode
* Python Jupyter Notebook

`Python File`
* Recommended if you want to integrate it to a website (ie: Python Flask web app)

`Google Collab (GPU requirements)`
* Cloud Computing

___

## `Useful Python libraries for ML`

### `Data Data Mining`

* [BeautifulSoup](https://www.crummy.com/software/BeautifulSoup/bs4/doc/)
* [Scrapy](https://scrapy.org/)

### `Data Source`

* [Kaggle](https://www.kaggle.com/datasets)
* [UCI ML repository](https://archive.ics.uci.edu/ml/index.php)
* Scrap from website
* API calls

### `Data Processing`

* [Pandas](https://pandas.pydata.org/)
* [Numpy](https://numpy.org/)
* [Scipy](https://scipy.org/)

Depending on what model you are choosing: For example, image dataset;
Yelp review for NLP model etc

___

## Useful Python libraries for ML

### `Visualizations For data visualization`

* [Matplotlib](https://matplotlib.org/)
* [Seaborn](https://seaborn.pydata.org/)
* [Plotly](https://plotly.com/)

___

## Useful Python libraries for ML 

### ML Models

* [`Sklearn`](https://scikit-learn.org/stable/): various classification, regression and clustering algorithms
* [`Tensorflow`](https://www.tensorflow.org/): various tasks, but particular focus on training and inference of deep neural networks
* [`Pytorch`](https://pytorch.org/): neural network, computer vision and natural language processing
* [`Keras`](https://keras.io/about/): primarily for for developing and evaluating deep learning models.

___

## ML Resources & Support

* Ed 
* CS50 Intro to Artificial Intelligence
* Python Libraries Documentation
* Kaggle 
* Towards Data Science blog
* Machine learning mastery blog
* Stack Overflow ● Github

___

## ML Ethics

* [Deep Fake Example in CS50](https://www.youtube.com/watch?v=Sv4GKbmzjmM)
* [Prof Finale Doshi-Valez: The importance of explainability in AI](https://youtu.be/4lIr8rgo5zE)
* [MIT 6.S191:AI biases & Fairness](https://youtu.be/wmyVODy_WD8)
* [AI robustness](https://youtu.be/eGQ4wqCGjXA)
* [The Alignment Problem: Aligning ML with human values](https://youtu.be/CzoVn8LUaDs)
* [Alan Turing Institute: Fairness, transparency, privacy](https://www.turing.ac.uk/research/interest-groups/fairness-transparency-privacy)

___

## Resources

### `Speech Recognition`

- [Python Speech Recognition (Real Python)](https://realpython.com/python-speech-recognition/)
- [Speech Recognition 3.10.0](https://pypi.org/project/SpeechRecognition/)

- `API`s:
    - [Speech-to-Text with Python](https://codelabs.developers.google.com/codelabs/cloud-speech-text-python3#0)

- `Encoders`:
    - [Wave2Vec2](https://huggingface.co/docs/transformers/model_doc/wav2vec2)
    - [Hubert](https://huggingface.co/docs/transformers/model_doc/hubert)

- `Decoders`:
    - [bert-base-multilingual-cased](https://huggingface.co/bert-base-multilingual-cased)
    - [bert-tiny](https://huggingface.co/prajjwal1/bert-tiny)
    - [GPT-2](https://huggingface.co/gpt2)
    - [FLAN-T5](https://huggingface.co/google/flan-t5-base)
    - [Speech2Text2](https://huggingface.co/docs/transformers/model_doc/speech_to_text_2)

-  [Transformers](https://huggingface.co/transformers) to use [Multimodal Speech Encoder/Decoder Models](https://huggingface.co/docs/transformers/model_doc/speech-encoder-decoder) for the text-to-speech model with any `pretrained speech autoencoding model` as the `encoder` and any `pretrained autoregressive model` as the `decoder`.

___

Return [CS50](/README.md)