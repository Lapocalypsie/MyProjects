/*
  Article.js

  The Article displays the contents of an article.

  props:
    article - The article to render
*/
import styles from "../styles/Article.module.css";
import ArticleShape from "./ArticleShape";

export default function Article({ article }) {
  const stringDate = new Date(article.edited).toLocaleString();
  return (
    <div className={styles.article}>
      <h2>{article.title}</h2>
      <p>{article.contents}</p>
      <p className={styles.timestamp}> {stringDate}</p>
    </div>
  );
}

Article.propTypes = {
  article: ArticleShape.isRequired,
};
