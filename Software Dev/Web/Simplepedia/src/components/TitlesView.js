/*
  TitleList.js

  This module displays a list of titles and reports when a user clicks on one.

  props:
    titles - an array of objects with title and id properties
    setCurrentArticle - a callback that expects an article as an argument

*/
import PropTypes from "prop-types";

export default function TitlesView({ titles, setCurrentArticle }) {
  const copyArticles = [...titles].sort((a, b) =>
    a.title.localeCompare(b.title)
  );

  const returnArticle = (article) => {
    setCurrentArticle(article);
  };

  return (
    <ul>
      {copyArticles.map((title1) => (
        <li
          key={title1.title}
          data-testid="title"
          onClick={() => returnArticle(title1)}
        >
          {title1.title}
        </li>
      ))}
    </ul>
  );
}

TitlesView.propTypes = {
  titles: PropTypes.arrayOf(
    PropTypes.shape({
      id: PropTypes.number.isRequired,
      title: PropTypes.string.isRequired,
    })
  ).isRequired,
  setCurrentArticle: PropTypes.func.isRequired,
};
