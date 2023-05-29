import PropTypes from "prop-types";
import IndexBar from "../../components/IndexBar";
import ArticleShape from "../../components/ArticleShape";
import Article from "../../components/Article";
import ButtonBar from "../../components/ButtonBar";
import { useRouter } from "next/router";

export default function Simplepedia({ currentArticle, setCurrentArticle }) {
  const router = useRouter();

  const handleClick = (event) => {
    if (event === "add") {
      router.push("/edit");
    } else if (event === "edit" && currentArticle !== null) {
      router.push(`/articles/${currentArticle.id}/edit`);
    }
  };

  return (
    <>
      <IndexBar
        setCurrentArticle={setCurrentArticle}
        currentArticle={currentArticle}
      />
      {currentArticle ? (
        <Article
          article={currentArticle}
          setCurrentArticle={setCurrentArticle}
        />
      ) : null}
      <ButtonBar
        allowEdit={currentArticle !== undefined}
        handleClick={handleClick}
      />
    </>
  );
}

Simplepedia.propTypes = {
  currentArticle: ArticleShape,
  setCurrentArticle: PropTypes.func.isRequired,
};
